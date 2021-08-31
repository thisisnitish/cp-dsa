/*
Leetcode Question 76. Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/
*/

class Solution
{
public:
    //Time: O(N), Space: O(N)
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";
        unordered_map<char, int> mp;
        //store the frequency of the t string
        for (auto c : t)
            mp[c]++;

        int i = 0, j = 0, result = INT_MAX, count = mp.size();
        string ans;

        while (j < s.size())
        {

            //calculation I
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
            }

            if (count > 0)
                j++;
            else if (count == 0)
            {
                //calculation II
                while (count == 0)
                {
                    if (j - i + 1 < result)
                    {
                        result = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                    if (mp.find(s[i]) != mp.end())
                    {
                        mp[s[i]]++;
                        if (mp[s[i]] == 1)
                        {
                            count++;
                            result = min(result, j - i + 1);
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
