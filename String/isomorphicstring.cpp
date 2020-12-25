/*
Leetcode Question 205. Isomorphic Strings
https://leetcode.com/problems/isomorphic-strings/
*/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.empty())
            return true;
        return helper(s, t) && helper(t, s);
    }

    bool helper(string s, string t)
    {
        int i, n = s.size();
        unordered_map<char, char> m;
        for (i = 0; i != n; i++)
        {
            if (!m.count(s[i]))
            {
                m.insert({s[i], t[i]});
            }
            else if (m[s[i]] != t[i])
                return false;
        }
        return true;
    }
};