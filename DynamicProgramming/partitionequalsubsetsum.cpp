/*
Leetcode Question 416. Partition Equal Subset Sum
https://leetcode.com/problems/partition-equal-subset-sum/
*/

/*the basic idea to use the subset sum impelementation, basically find the sum and if it is odd then
it is impossible to find the two equal parts but if it is even then we can find the subsets. To do that,
we have to use subset sum logic only the sum will be sum/2 and other things will be same.
*/

/*
This is a variation of subset sum problem and subset sum problem is itself a knapsack
variation. So this question can also be done with the help of knapsack or subset sum
variation.
*/
// Recursive
class Solution
{
public:
    // Time: O(2^n), Space: O(2^n)
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;
        return subsetSum(nums, sum / 2, nums.size());
    }

    bool subsetSum(vector<int> &nums, int sum, int n)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        if (nums[n - 1] <= sum)
        {
            return subsetSum(nums, sum - nums[n - 1], n - 1) || subsetSum(nums, sum, n - 1);
        }
        else
        {
            return subsetSum(nums, sum, n - 1);
        }
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;
        vector<vector<int> > memo(nums.size() + 1, vector<int>(sum / 2 + 1, -1));
        return subsetSum(nums, sum / 2, nums.size(), memo);
    }

    bool subsetSum(vector<int> &nums, int sum, int n, vector<vector<int> > &memo)
    {
        if (sum == 0)
            return memo[n][sum] = true;
        if (n == 0)
            return memo[n][sum] = false;

        if (memo[n][sum] != -1)
            return memo[n][sum];

        if (nums[n - 1] <= sum)
        {
            return memo[n][sum] = subsetSum(nums, sum - nums[n - 1], n - 1, memo) || subsetSum(nums, sum, n - 1, memo);
        }
        else
        {
            return memo[n][sum] = subsetSum(nums, sum, n - 1, memo);
        }
    }
};

// Tabulation
class Solution
{
public:
    // Time: O(n*sum/2), Space: O(n*sum/2)
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;
        return subsetSum(nums, sum / 2, nums.size());
    }

    bool subsetSum(vector<int> &nums, int sum, int n)
    {
        vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1));

        // initializing the table
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        // filling the values in small problems
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};
