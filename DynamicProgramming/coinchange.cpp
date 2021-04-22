/*
Leetcode Question 322. Coin Change
https://leetcode.com/problems/coin-change/
*/

class Solution
{
public:
    /*Here, Everything is same concept wise from coin change 2 but 
    there is twist in initialization, other than that everything is 
    same. Time: O(n*amount) Space: O(n*amount)*/
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int> > dp(n + 1, vector<int>(amount + 1));

        //initialization
        //first row
        for (int i = 0; i < amount + 1; i++)
            dp[0][i] = INT_MAX - 1;

        //first column
        for (int i = 1; i < n + 1; i++)
            dp[i][0] = 0;

        //second row
        for (int j = 1; j < amount + 1; j++)
        {
            if (j % coins[0] == 0)
                dp[1][j] = j / coins[0];
            else
                dp[1][j] = INT_MAX - 1;
        }

        //solving the problems
        //becasue we have been asked for finding the minimum number of
        //coins so we have to add the 1 to the choices
        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        /*because we have done the initialization with INT_MAX-1, so after 
        the calculation may be the value will be INT_MAX or INT_MAX-1,
        if that is the case then return -1 (A.T.Q.) else return the value*/
        if (dp[n][amount] == INT_MAX || dp[n][amount] == INT_MAX - 1)
            return -1;
        return dp[n][amount];
    }
};