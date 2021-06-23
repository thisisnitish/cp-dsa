/*
Leetcode Question 792. Number of Matching Subsequences
https://leetcode.com/problems/number-of-matching-subsequences/
*/

//Recursive + Memoization
class Solution
{
public:
    //Time: O(length(s) * length(word) * word.size()), Space: O(n*m);
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;
        for (auto word : words)
        {
            vector<vector<int> > memo(s.length() + 1, vector<int>(word.length() + 1, -1));
            int length = isSubsequence(s, word, s.length(), word.length(), memo);
            if (length == word.length())
                count++;
        }
        return count;
    }

    int isSubsequence(string &s, string &t, int m, int n, vector<vector<int> > &memo)
    {
        if (m == 0 || n == 0)
            return 0;

        if (memo[m][n] != -1)
            return memo[m][n];

        if (s[m - 1] == t[n - 1])
            return 1 + isSubsequence(s, t, m - 1, n - 1, memo);
        else
            return max(isSubsequence(s, t, m - 1, n, memo), isSubsequence(s, t, m, n - 1, memo));
    }
};

//Using normal logic
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;
        for (auto word : words)
        {
            if (isSubsequence(s, word))
                count++;
        }
        return count;
    }

    //check if t is the susbsequence of s
    bool isSubsequence(string s, string t)
    {
        int n = s.length();
        int idx = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[idx])
                idx++;
        }
        return (idx == t.length());
    }
};

//optimized approach
class Solution
{
public:
    //m => size of array
    //len1 => s.length()
    //len2 => word.length()
    //Time: O(m * min(len1, len2))
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;
        unordered_map<string, int> mp;
        for (auto word : words)
        {

            if (mp.find(word) != mp.end())
            {
                count += mp[word];
                continue;
            }

            int n = s.length();
            int idx = 0;
            for (int i = 0; i < n and idx < word.length(); i++)
            {
                if (s[i] == word[idx])
                    idx++;
            }

            mp[word] = (idx == word.length());
            count += (idx == word.length());
        }
        return count;
    }
};
