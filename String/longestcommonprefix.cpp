/*
Leetcode 14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/
*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        //string result="";

        for (int i = 0; i < strs[0].size(); i++)
        {
            char c = strs[0].at(i);

            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].length() || strs[j].at(i) != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};