/*
Leetcode Question 97. Interleaving String
https://leetcode.com/problems/interleaving-string/
*/

// Sol 1 - https://www.youtube.com/watch?v=79g3LJoQk_U
// Sol 2 - https://www.youtube.com/watch?v=3Rw3p9LrgvE


// Recursive
class Solution
{
public:
    // Time: O(2^m+n), Space: O(m+n)
    bool checkInterleave(string s1, string s2, string s3, int i, int j)
    {
        // base condition
        if (i == s1.length() && j == s2.length())
            return true;

        if (i < s1.length() && s1[i] == s3[i + j])
        {
            bool ans = checkInterleave(s1, s2, s3, i + 1, j);
            if (ans)
                return true;
        }
        if (j < s2.length() && s2[j] == s3[i + j])
        {
            bool ans = checkInterleave(s1, s2, s3, i, j + 1);
            if (ans)
                return true;
        }

        return false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length();

        if (m + n != s3.length())
            return false;
        return checkInterleave(s1, s2, s3, 0, 0);
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    bool checkInterleave(string s1, string s2, string s3, int i, int j, vector<vector<int> > &memo)
    {
        // base condition
        if (i == s1.length() && j == s2.length())
            return true;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (i < s1.length() && s1[i] == s3[i + j])
        {
            bool ans = checkInterleave(s1, s2, s3, i + 1, j, memo);
            memo[i][j] = ans;
            if (ans)
                return true;
        }
        if (j < s2.length() && s2[j] == s3[i + j])
        {
            bool ans = checkInterleave(s1, s2, s3, i, j + 1, memo);
            memo[i][j] = ans;
            if (ans)
                return true;
        }
        memo[i][j] = false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length();

        if (m + n != s3.length())
            return false;
        vector<vector<int> > memo(m + 1, vector<int>(n + 1, -1));
        return checkInterleave(s1, s2, s3, 0, 0, memo);
    }
};

// Bottom Up, Tabulation
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length();

        if (m + n != s3.length())
            return false;

        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, 0));

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                // for the first cell, because s1 and s2 both are empty and
                // you can create s3 i.e. ""
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                {
                    // handle the first row separately where s1 will be empty and
                    // s2 will not be empty
                    dp[i][j] = s2[j - 1] == s3[i + j - 1] ? dp[i][j - 1] : false;
                }
                else if (j == 0)
                {
                    // handle the first column separately where s2 will be empty and
                    // s1 will not be empty
                    dp[i][j] = s1[i - 1] == s3[i + j - 1] ? dp[i - 1][j] : false;
                }
                else
                {
                    // if the last character from s1 == last character from s3
                    if (s1[i - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i - 1][j];

                    /*if the last character from s2 == last character from s3
                    this will only happen when char from s1 will not be equal to
                    char from s3*/
                    if (!dp[i][j] && s2[j - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
