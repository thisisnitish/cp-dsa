/*
Leetcode Question 1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/
*/

//here we have discussed all the 3 approaches
//Recursion
class Solution
{
public:
    /*Time: O(2^n)*/
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();

        return helper(text1, text2, m, n);
    }

    int helper(string text1, string text2, int m, int n)
    {
        //when the string lenght is 0
        if (m == 0 || n == 0)
            return 0;

        //when the characters are equal just decrease the length and call recursively
        if (text1[m - 1] == text2[n - 1])
            return 1 + helper(text1, text2, m - 1, n - 1);
        else //when the characters are not equal then we have to check all possible cases
            return max(helper(text1, text2, m - 1, n), helper(text1, text2, m, n - 1));
    }
};

//Memoization (Top-Down)
class Solution
{
public:
    /*Time: O(m*n), Space: O(m*n)*/
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        //initializing with -1
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        return helper(text1, text2, m, n, dp);
    }

    int helper(string &text1, string &text2, int m, int n, vector<vector<int> > &dp)
    {

        if (m == 0 || n == 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (text1[m - 1] == text2[n - 1])
            return dp[m][n] = 1 + helper(text1, text2, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(
                       helper(text1, text2, m - 1, n, dp),
                       helper(text1, text2, m, n - 1, dp));
    }
};

//Bottom Up
class Solution
{
public:
    /*Time: O(m*n), Space: O(m*n)*/
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int> > dp(m + 1, vector<int>(n + 1));

        //initialization
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        //solving the subproblems to solve the bigger problems
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};