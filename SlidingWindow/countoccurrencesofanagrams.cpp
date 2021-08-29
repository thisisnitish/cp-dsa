/*
Count Occurences of Anagrams 
https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#
*/

class Solution
{
public:
    int search(string pat, string txt)
    {
        int i = 0, j = 0, k, count, ans = 0;
        unordered_map<char, int> mp;
        //store the freq of every element from pat
        for (auto c : pat)
        {
            mp[c]++;
        }
        count = mp.size();
        k = pat.size();
        while (j < txt.size())
        {
            if (mp.find(txt[j]) != mp.end())
            {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0)
                    count--;
            }
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                if (count == 0)
                    ans++;
                if (mp.find(txt[i]) != mp.end())
                {
                    mp[txt[i]]++;
                    if (mp[txt[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
