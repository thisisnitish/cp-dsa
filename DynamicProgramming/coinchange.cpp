/*
Leetcode Question 322. Coin Change
https://leetcode.com/problems/coin-change/
*/

// Recursive
class Solution
{
public:
    // Time: O(2^N), Space: O(2^N)
    int minNumOfCoins(vector<int> &coins, int amount, int n)
    {
        // base case
        if (n == 0 || amount == 0)
            return amount == 0 ? 0 : INT_MAX - 1;

        if (coins[n - 1] <= amount)
        {
            return min(1 + minNumOfCoins(coins, amount - coins[n - 1], n),
                       minNumOfCoins(coins, amount, n - 1));
        }
        else
        {
            return minNumOfCoins(coins, amount, n - 1);
        }
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int minCoins = minNumOfCoins(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(n*amount), Space: O(n*amount + Stack Space)
    int minNumOfCoins(vector<int> &coins, int amount, int n, vector<vector<int> > &memo)
    {
        // base case
        if (n == 0 || amount == 0)
            return memo[n][amount] = amount == 0 ? 0 : INT_MAX - 1;

        if (memo[n][amount] != -1)
            return memo[n][amount];

        if (coins[n - 1] <= amount)
        {
            return memo[n][amount] = min(1 +
                                             minNumOfCoins(coins, amount - coins[n - 1], n, memo),
                                         minNumOfCoins(coins, amount, n - 1, memo));
        }
        else
        {
            return memo[n][amount] = minNumOfCoins(coins, amount, n - 1, memo);
        }
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int> > memo(coins.size() + 1, vector<int>(amount + 1, -1));
        int minCoins = minNumOfCoins(coins, amount, coins.size(), memo);
        return minCoins == INT_MAX - 1 ? -1 : minCoins;
    }
};

// Tabulation
class Solution
{
public:
    // Time: O(n*amount), Space: O(n*amount)
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int> > dp(n + 1, vector<int>(amount + 1));

        // initialization
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = j == 0 ? 0 : INT_MAX - 1;
            }
        }

        // solving the subproblems
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][amount] != INT_MAX - 1 ? dp[n][amount] : -1;
    }
};

// Tabulation
class Solution
{
public:
    // Time: O(n*amount), Space: O(n*amount)
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int> > dp(n + 1, vector<int>(amount + 1));

        // initialization
        // first row
        for (int i = 0; i < amount + 1; i++)
            dp[0][i] = INT_MAX - 1;

        // first column
        for (int i = 1; i < n + 1; i++)
            dp[i][0] = 0;

        // second row
        for (int j = 1; j < amount + 1; j++)
        {
            if (j % coins[0] == 0)
                dp[1][j] = j / coins[0];
            else
                dp[1][j] = INT_MAX - 1;
        }

        // solving the problems
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
        if (dp[n][amount] == INT_MAX || dp[n][amount] == INT_MAX - 1)
            return -1;
        return dp[n][amount];
    }
};
