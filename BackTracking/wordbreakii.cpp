/*
Leetcode Question 140. Word Break II
https://leetcode.com/problems/word-break-ii/
*/

class Solution
{
public:
    unordered_map<string, vector<string>> dp;
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        /*the basic idea is take element from the list and start searching in the string*/
        if (dp.find(s) != dp.end())
            return dp[s];
        vector<string> result;

        for (string w : wordDict)
        {
            //comparing substring to the w string
            if (s.substr(0, w.length()) == w)
            {
                //this will happen when you will reach end of the string recursively
                if (w.length() == s.length())
                {
                    result.push_back(w);
                }
                else
                {
                    vector<string> temp = wordBreak(s.substr(w.length()), wordDict);
                    for (string t : temp)
                    {
                        result.push_back(w + " " + t);
                    }
                }
            }
        }
        dp[s] = result;
        return result;
    }
};