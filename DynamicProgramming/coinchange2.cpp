/*
Leetcode Question 518. Coin Change 2
https://leetcode.com/problems/coin-change-2/
*/

/*
This is a same question as unbounded knapsack, but we need to keep in mind subset
sum problem. We have to ignore value array from knapsack solution for this problem.
*/
// Recursive
class Solution
{
public:
    // Time: O(2^N), Space: O(2^N)
    int coinChange2(vector<int> &coins, int amount, int n)
    {
        // base case
        if (amount == 0)
            return 1;
        if (n == 0)
            return 0;

        if (coins[n - 1] <= amount)
        {
            return coinChange2(coins, amount - coins[n - 1], n) +
                   coinChange2(coins, amount, n - 1);
        }
        else
        {
            return coinChange2(coins, amount, n - 1);
        }
    }

    int change(int amount, vector<int> &coins)
    {
        return coinChange2(coins, amount, coins.size());
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(n*amount), Space: O(n*amount + Stack Space)
    int coinChange2(vector<int> &coins, int amount, int n, vector<vector<int> > &memo)
    {
        // base case
        if (amount == 0)
            return 1;
        if (n == 0)
            return 0;

        if (memo[n][amount] != -1)
            return memo[n][amount];

        if (coins[n - 1] <= amount)
        {
            return memo[n][amount] = coinChange2(coins, amount - coins[n - 1], n, memo) +
                                     coinChange2(coins, amount, n - 1, memo);
        }
        else
        {
            return memo[n][amount] = coinChange2(coins, amount, n - 1, memo);
        }
    }

    int change(int amount, vector<int> &coins)
    {
        vector<vector<int> > memo(coins.size() + 1, vector<int>(amount + 1, -1));
        return coinChange2(coins, amount, coins.size(), memo);
    }
};

// Tabulation
class Solution
{
public:
    // Time: O(n*amount), Space: O(n*amount)
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int> > dp(n + 1, vector<int>(amount + 1));

        // initializing
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

        // solving the subproblems
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }
};
