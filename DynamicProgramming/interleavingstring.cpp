/*
Leetcode Question 97. Interleaving String
https://leetcode.com/problems/interleaving-string/
*/

//Recursive
class Solution
{
public:
    //Time: O(2^m+n), Space: O(m+n)
    bool checkInterleave(string s1, string s2, string s3, int i, int j)
    {
        //base condition
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

//Recursive + Memoization
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    bool checkInterleave(string s1, string s2, string s3, int i, int j, vector<vector<int> > &memo)
    {
        //base condition
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

//Bottom Up, Tabulation
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length();

        if (m + n != s3.length())
            return false;

        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                //for the first value, because s1 and s2 are empty and you can create s3
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                {
                    //filling the first row
                    dp[i][j] = s2[j - 1] == s3[i + j - 1] ? dp[i][j - 1] : 0;
                }
                else if (j == 0)
                {
                    //filling the second row
                    dp[i][j] = s1[i - 1] == s3[i + j - 1] ? dp[i - 1][j] : 0;
                }
                else
                {
                    /*
                    if the last character from s1 == last character from s3
                    */
                    if (s1[i - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i - 1][j];
                    /*
                        if the last character from s2 == last character from s3
                    */
                    if (!dp[i][j] && s2[j - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i][j - 1];
                    /*
                    for the 3rd case, we don't need to check, i.e.
                    if the last character from s1 == last character from s3 and
                    last character from s2 == last character from s3, if one of
                    above condition will true then this condition will fullfill
                    */
                }
            }
        }
        return dp[m][n];
    }
};
