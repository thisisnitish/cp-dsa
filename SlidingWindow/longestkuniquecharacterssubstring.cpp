/*
Longest K unique characters substring 
https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#
*/

class Solution
{
public:
    //Time: O(N), Space: O(N)
    int longestKSubstr(string s, int k)
    {
        int i = 0, j = 0, result = -1;
        unordered_map<char, int> mp;

        while (j < s.length())
        {
            //calculation I
            mp[s[j]]++;

            if (mp.size() < k)
                j++;
            else if (mp.size() == k)
            {
                //calculation II
                result = max(result, j - i + 1);
                j++;
            }
            else if (mp.size() > k)
            {
                //calculation III
                while (mp.size() > k)
                {
                    mp[s[i]]--;

                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return result;
    }
};
