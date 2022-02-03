/*
Leetcode Question 70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/
*/

/*This is a variation of Fibonacci*/
// Recursive
class Solution
{
public:
    // Time: O(2^n), Space: O(2^n)
    int climbStairs(int n)
    {
        // base case
        if (n == 0 || n == 1)
            return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(n), Space: O(n)
    vector<int> memo;
    int countSteps(int n)
    {
        // base case
        if (n == 0 || n == 1)
            return memo[n] = 1;
        if (memo[n] != -1)
            return memo[n];

        return memo[n] = countSteps(n - 1) + countSteps(n - 2);
    }
    int climbStairs(int n)
    {
        memo.resize(n + 1, -1);
        return countSteps(n);
    }
};

// Tabulation
class Solution
{
public:
    // Time: O(n), Space: O(n)
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < n + 1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
