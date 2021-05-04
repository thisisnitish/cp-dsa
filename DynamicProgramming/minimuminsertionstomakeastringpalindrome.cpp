/*
Leetcode Question 1312. Minimum Insertion Steps to Make a String Palindrome
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

class Solution
{
public:
    /*Since this question is same as the deletion in place of insertion, if we
    observe the question carefully, you will find that min. no. of insertion ==
    min. no. of deletion to make a string palindrome. So, we have to use the 
    same code. Time: O(m*n), Space: O(m*n)*/
    int minInsertions(string s)
    {
        string X = s;
        string Y = s;
        reverse(Y.begin(), Y.end());
        int m = s.length();
        int n = m;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        int insertion = m - longestPalindormeSubsq(X, Y, m, n, dp);
        return insertion;
    }

    int longestPalindormeSubsq(string &X, string &Y, int m, int n, vector<vector<int> > &dp)
    {
        if (m == 0 || n == 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];

        if (X[m - 1] == Y[n - 1])
            return dp[m][n] = 1 + longestPalindormeSubsq(X, Y, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(
                       longestPalindormeSubsq(X, Y, m - 1, n, dp),
                       longestPalindormeSubsq(X, Y, m, n - 1, dp)
                    );
    }
};