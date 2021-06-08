/*
Leetcode Question 746. Min Cost Climbing Stairs
https://leetcode.com/problems/min-cost-climbing-stairs/
*/

//Recursive
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int idx = cost.size();
        return min(helper(cost, idx - 1), helper(cost, idx - 2));
    }

    int helper(vector<int> &cost, int idx)
    {
        if (idx == 0 || idx == 1)
            return cost[idx];

        return min(helper(cost, idx - 1), helper(cost, idx - 2)) + cost[idx];
    }
};

//Recursive + Memoization, Top Down
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int idx = cost.size();

        //not idx+1 because first block will be empty so don't do it
        vector<int> memo(idx, -1);
        return min(helper(cost, idx - 1, memo), helper(cost, idx - 2, memo));
    }

    int helper(vector<int> &cost, int idx, vector<int> &memo)
    {
        if (idx == 0 || idx == 1)
            return cost[idx];

        if (memo[idx] != -1)
            return memo[idx];

        memo[idx] = min(helper(cost, idx - 1, memo), helper(cost, idx - 2, memo)) + cost[idx];
        return memo[idx];
    }
};

//Bottom Up
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int idx = cost.size();
        vector<int> dp(idx, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < idx; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[idx - 1], dp[idx - 2]);
    }
};
