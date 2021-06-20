/*
Leetcode Question 629. K Inverse Pairs Array
https://leetcode.com/problems/k-inverse-pairs-array/
*/

//Recursive
class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        if (n == 0)
            return 0;
        if (k == 0)
            return 1;

        int inverse = 0;
        for (int i = 0; i <= min(k, n - 1); i++)
            inverse += (kInversePairs(n - 1, k - i)) % 1000000007;

        return inverse;
    }
};

//Recursive + Memoization
class Solution
{
public:
    //Time: O(n^2*k), Space: O(n^2)
    int kInversePairs(int n, int k)
    {
        vector<vector<int> > memo(1001, vector<int>(1001, -1));
        return helper(n, k, memo);
    }

    int helper(int n, int k, vector<vector<int> > &memo)
    {
        if (n == 0)
            return 0;
        if (k == 0)
            return 1;

        if (memo[n][k] != -1)
            return memo[n][k];

        int inverse = 0;
        for (int i = 0; i <= min(k, n - 1); i++)
            inverse = (inverse + helper(n - 1, k - i, memo)) % 1000000007;

        memo[n][k] = inverse;
        return inverse;
    }
};

//Bottom Up Approach
class Solution
{
public:
    //Time: O(n*k) Space: O(n*k)
    int kInversePairs(int n, int k)
    {
        int mod = 1000000007;
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));

        //initialzation
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int N = 1; N <= n; N++)
        {
            for (int K = 1; K <= k; K++)
            {
                dp[N][K] = (dp[N - 1][K] + dp[N][K - 1]) % mod;
                if (K - N >= 0)
                {
                    dp[N][K] = (dp[N][K] - dp[N - 1][K - N] + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};
