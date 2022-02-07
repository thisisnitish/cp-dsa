/*
Leetcode Question 746. Min Cost Climbing Stairs
https://leetcode.com/problems/min-cost-climbing-stairs/
*/

/*
This is a variation for LC: 70
*/
// Recursive
class Solution
{
public:
    // Time: O(2^N), Space: O(2^N)
    int findMinCost(vector<int> &cost, int idx)
    {
        // base case
        if (idx >= cost.size())
            return 0;

        return cost[idx] + min(findMinCost(cost, idx + 1), findMinCost(cost, idx + 2));
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        /*Since you can start from idx 0 or 1. You have to explore both the
        paths and get the min result*/
        return min(findMinCost(cost, 0), findMinCost(cost, 1));
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(N), Space: O(N)
    int findMinCost(vector<int> &cost, int idx, vector<int> &memo)
    {
        // base case
        if (idx >= cost.size())
            return 0;

        if (memo[idx] != -1)
            return memo[idx];

        return memo[idx] = cost[idx] +
                           min(findMinCost(cost, idx + 1, memo), findMinCost(cost, idx + 2, memo));
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> memo(cost.size(), -1);
        return min(findMinCost(cost, 0, memo), findMinCost(cost, 1, memo));
    }
};

// Tabulation
class Solution
{
public:
    // Time: O(N), Space: O(N)
    int minCostClimbingStairs(vector<int> &cost)
    {
        // dp[i] is defined as the min cost to reach ith step
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

// Space Optimsed
class Solution
{
public:
    // Time: O(1)
    int minCostClimbingStairs(vector<int> &cost)
    {
        int firstStep = cost[0], secondStep = cost[1];
        int nextStep;

        for (int i = 2; i < cost.size(); i++)
        {
            nextStep = cost[i] + min(firstStep, secondStep);
            firstStep = secondStep;
            secondStep = nextStep;
        }
        return min(firstStep, secondStep);
    }
};
