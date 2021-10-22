/*
Leetcode Question 140. Word Break II
https://leetcode.com/problems/word-break-ii/
*/

// Solution 1
class Solution
{
public:
    // Time: O(N^N)
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> result;
        string ans = "";
        findWordBreak(0, s, ans, wordDict, result);
        return result;
    }

    void findWordBreak(int idx, string s, string ans, vector<string> &wordDict, vector<string> &result)
    {

        if (idx == s.size())
        {
            // if we go index out of bound then remove the last space and store that string
            ans.pop_back();
            result.push_back(ans);
            return;
        }

        string str = "";
        for (int i = idx; i < s.size(); i++)
        {
            str.push_back(s[i]);

            if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end())
            {
                findWordBreak(i + 1, s, ans + str + " ", wordDict, result);
            }
        }
    }
};

// Solution 2
class Solution
{
public:
    // Time: O(N^N)
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> us;
        vector<string> result;
        for (auto c : wordDict)
        {
            us.insert(c);
        }
        string ans = "";
        findWordBreak(0, s, ans, us, result);
        return result;
    }

    void findWordBreak(int idx, string s, string ans, unordered_set<string> &us, vector<string> &result)
    {

        if (idx == s.size())
        {
            // if we go index out of bound then remove the last space and store that string
            ans.pop_back();
            result.push_back(ans);
            return;
        }

        string str = "";
        for (int i = idx; i < s.size(); i++)
        {
            str.push_back(s[i]);

            if (us.count(str))
            {
                findWordBreak(i + 1, s, ans + str + " ", us, result);
            }
        }
    }
};
