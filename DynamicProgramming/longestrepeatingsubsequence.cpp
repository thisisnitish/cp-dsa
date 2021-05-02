/*
Longest Repeating Subsequence 
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
*/

class Solution
{
public:
    /*the basic idea is, this problem can be reduced to the problem
	of LCS and but the only requirement is that the two subsequence 
	don’t have same string character at same position, except this
	everything is same. It can be done using Memoization also
    Time: O(m*n), Space: O(m*n)*/
    int LongestRepeatingSubsequence(string str)
    {
        string X = str;
        string Y = str;
        int m = str.size();
        int n = m;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));

        //intializing
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        //solving the subproblems
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (X[i - 1] == Y[j - 1] && i != j)
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};