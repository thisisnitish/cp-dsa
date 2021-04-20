/*
Leetcode Question 518. Coin Change 2
https://leetcode.com/problems/coin-change-2/
*/

class Solution
{
public:
    /*the basic idea is that it is based on the unbounded knapsack problem
    so before doing this understand the concept of unbounded knapsack problem
    then only do this preblem. Everything is same, only the thing we have to
    change is to add the choices because we have been asked for find the number
    of combinations. We are using Bottom Up approach 
    Time: O(n*amount), Space: O(n*amount)*/
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int> > dp(n + 1, vector<int>(amount + 1));

        //initializing
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        //solving the small problems to find the bigger one
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];   //adding the choices
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }
};