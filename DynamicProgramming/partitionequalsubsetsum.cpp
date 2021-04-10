/*
Leetcode Question 416. Partition Equal Subset Sum
https://leetcode.com/problems/partition-equal-subset-sum/
*/

class Solution
{
public:
    /*the basic idea to use the subset sum impelementation, basically
    find the sum and if it is odd then it is impossible to find the two
    equal parts but if it is even then we can find the subsets. To do that,
    we have to use subset sum logic only the sum will be sum/2 and other things
    will be same. Time: O(n*sum) Space: O(n*sum)*/
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;
        else
            return subsetSum(nums, sum / 2, nums.size());
    }

    bool subsetSum(vector<int> &nums, int sum, int n)
    {
        vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1));

        //initializing the table
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

        //filling the values in small problems
        //and finding the big problem - Bottom-up Approach
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