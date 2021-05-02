/*
Longest Common Substring
https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
*/

class Solution
{
public:
    /*Time: O(m*n), Space: O(m*n)*/
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int result = 0;
        vector<vector<int> > dp(n + 1, vector<int>(m + 1));

        //initialization
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        //solving the subproblems
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    //this could be done in separate array but we are doing in
                    //same loop
                    //since we want the longest string
                    result = max(result, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return result;
    }
};