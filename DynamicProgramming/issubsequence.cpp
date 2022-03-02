/*
Leetcode Question 392. Is Subsequence
https://leetcode.com/problems/is-subsequence/
*/

// Recursive + Memoization
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    bool isSubsequence(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        vector<vector<int> > memo(m + 1, vector<int>(n + 1, -1));
        int subsequenceLength = lcs(s, t, m, n, memo);
        int isSubsequence = subsequenceLength == m;
        return isSubsequence;
    }

    int lcs(string &s, string &t, int m, int n, vector<vector<int> > &memo)
    {
        if (m == 0 || n == 0)
            return memo[m][n] = 0;
        if (memo[m][n] != -1)
            return memo[m][n];

        if (s[m - 1] == t[n - 1])
            return memo[m][n] = 1 + lcs(s, t, m - 1, n - 1, memo);
        else
            return memo[m][n] = max(lcs(s, t, m - 1, n, memo),
                                    lcs(s, t, m, n - 1, memo));
    }
};

// Tabulation - Bottom Up
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    bool isSubsequence(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        vector<vector<int> > dp(m + 1, vector<int>(n + 1));

        // initialization
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        // solving the subproblems
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int subsequenceLength = dp[m][n];
        int isSubsequence = subsequenceLength == m;
        return isSubsequence;
    }
};

// Optmized - Without DP (Just Two Pointers)
class Solution
{
public:
    // Time: O(N), Space: O(1)
    bool isSubsequence(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        while (j < n)
        {
            if (s[i] == t[j])
                i++, j++;
            else
                j++;
        }
        return (i == s.length());
    }
};