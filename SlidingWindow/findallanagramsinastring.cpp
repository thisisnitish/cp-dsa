/*
Leetcode Question 438. Find All Anagrams in a String
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

class Solution
{
public:
    //Time: O(N), Space: O(N)
    vector<int> findAnagrams(string s, string p)
    {
        int k = p.size();
        unordered_map<char, int> mp;
        for (auto c : p)
            mp[c]++;

        vector<int> result;

        //stores the number of distinct characters of anagram with their frequencies
        int count = mp.size();

        int i = 0, j = 0;
        while (j < s.size())
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
            }

            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                //if we hit the window of k size just store the i value, ofc that is
                //starting index of the anagram
                if (count == 0)
                    result.push_back(i);
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return result;
    }
};
