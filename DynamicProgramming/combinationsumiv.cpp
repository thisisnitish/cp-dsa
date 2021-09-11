/*
Leetcode Question 377. Combination Sum IV
https://leetcode.com/problems/combination-sum-iv/
*/

//1D DP
class Solution
{
public:
    //Time: O(n*target)
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<unsigned int> dp(target + 1);

        dp[0] = 1;

        for (int i = 1; i < target + 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[j] <= i)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

class Solution
{
public:
    //Time: O(n*target)
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int> > dp(n + 1, vector<int>(target + 1));

        //initializing
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < target + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        //solving the subproblems
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < target + 1; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
};
