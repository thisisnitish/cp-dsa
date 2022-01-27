/*
Leetcode Question 115. Distinct Subsequences
https://leetcode.com/problems/distinct-subsequences/
*/

// Recursive
class Solution
{
public:
    // Time: O(2^N), Space: O(2^N)
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        return lcs(s, t, m, n);
    }

    int lcs(string &s, string &t, int m, int n)
    {
        if (n == 0)
            return 1;
        if (m < n)
            return 0;

        if (s[m - 1] == t[n - 1])
            return lcs(s, t, m - 1, n - 1) + lcs(s, t, m - 1, n);
        else
            return lcs(s, t, m - 1, n);
    }
};

// Recursive + Memoization Top Down Approach
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<int> > memo(m + 1, vector<int>(n + 1, -1));
        return lcs(s, t, m, n, memo);
    }

    int lcs(string &s, string &t, int m, int n, vector<vector<int> > &memo)
    {
        if (n == 0)
            return memo[m][n] = 1;
        if (m < n)
            return memo[m][n] = 0;

        if (memo[m][n] != -1)
            return memo[m][n];

        if (s[m - 1] == t[n - 1])
            return memo[m][n] = lcs(s, t, m - 1, n - 1, memo) + lcs(s, t, m - 1, n, memo);
        else
            return memo[m][n] = lcs(s, t, m - 1, n, memo);
    }
};

// BottomUp Approach
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<unsigned long long> > dp(m + 1, vector<unsigned long long>(n + 1, 0));

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (i < j)
                    dp[i][j] = 0;
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};
