/*
Minimum number of deletions.
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1#
*/

/*the basic idea is if we observe the question carefully we can reduce
it to the LCS problem, basicallu if you make a copy of str and reverse 
it and try to find the LCS from both strings and then subtract LCS length
from the length of the str, we will get the answer. Time: O(m*n)
Space: O(m*n)*/
int lcs(string &X, string &Y, int m, int n, vector<vector<int> > &dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];

    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
    else
        return dp[m][n] = max(lcs(X, Y, m - 1, n, dp), lcs(X, Y, m, n - 1, dp));
}

int minDeletions(string str, int n)
{
    //complete the function here
    string X = str;
    string Y = str;
    //reverse the one string
    reverse(Y.begin(), Y.end());

    int m = n;
    //initializing the matrix
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
    int deletions = m - lcs(X, Y, m, n, dp);
    return deletions;
}