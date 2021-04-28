/*
Leetcode Question 509. Fibonacci Number
https://leetcode.com/problems/fibonacci-number/
*/

//Recusrion
class Solution
{
public:
    //Time: O(2^N), Space: O(N)
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

//Memoization - TopDown
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        return helper(dp, n);
    }

    int helper(vector<int> &dp, int n)
    {
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//Bottom Up
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int fib(int n)
    {
        vector<int> _fib(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            if (i == 0 || i == 1)
                _fib[i] = i;
            else
                _fib[i] = _fib[i - 1] + _fib[i - 2];
        }
        return _fib[n];
    }
};
