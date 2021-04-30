/*
Leetcode Question 516. Longest Palindromic Subsequence
https://leetcode.com/problems/longest-palindromic-subsequence/
*/

//Memoization-Top Down
class Solution
{
public:
    /*if you will see the problem very carefully and try to observe it
    you will find, this problem can be reduced to the LCS problem
    Time: O(m*n), Space: O(m*n)*/
    int longestPalindromeSubseq(string s)
    {

        //copying the string
        string X, Y;
        X = s;
        Y = s;

        //reverse the string so that we can perform the LCS(requires two strings)
        reverse(Y.begin(), Y.end());
        int m = X.size();
        int n = m;
        //initializing the matrix
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        return lcs(X, Y, m, n, dp);
    }

    int lcs(string &X, string &Y, int m, int n, vector<vector<int> > &dp)
    {
        if (m == 0 || n == 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (X[m - 1] == Y[n - 1])
            return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
    }
};

//Bottom Up
class Solution
{
public:
    /*Time: O(m*n), Space: O(m*n)*/
    int longestPalindromeSubseq(string s)
    {
        string X, Y;
        X = s;
        Y = s;
        reverse(Y.begin(), Y.end());
        int m = X.size();
        int n = m;
        return lcs(X, Y, m, n);
    }

    int lcs(string &X, string &Y, int m, int n)
    {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));

        //initializing
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j];
            }
        }

        //solving the subproblems
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};