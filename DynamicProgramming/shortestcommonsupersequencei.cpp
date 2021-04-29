/*
Shortest Common Supersequence
https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#
*/

class Solution
{
public:
    //Function to find length of shortest common supersequence of two strings.
    /*the basic idea is that find the lcs length from both the strings
    and concatenate both the string to make the third one and just remove
    the lcs length from concatenated string, we will get the output.
    Time: O(m*n), Space: O(m*n)*/
    int lcs(string tempX, string tempY, int m, int n)
    {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));

        //intializing
        for (int i = 0; i < m + 1; i++)
            for (int j = 0; j < n + 1; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

        //solving the subproblems
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (tempX[i - 1] == tempY[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }

    int shortestCommonSupersequence(char *X, char *Y, int m, int n)
    {
        string tempX = "";
        string tempY = "";

        for (int i = 0; i < m; i++)
            tempX.push_back(X[i]);
        for (int i = 0; i < n; i++)
            tempY.push_back(Y[i]);

        return m + n - lcs(tempX, tempY, m, n);
    }
};
