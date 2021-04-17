/*
Leetcode Question 494. Target Sum
https://leetcode.com/problems/target-sum/
*/

class Solution
{
public:
    /*the basic idea is that after reducing this problem it is reduced to count of 
    subset sum problem and other than that everything is same. 
    Time: O(n*sum), Space: O(n*sum)*/
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        //calculating the array sum
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        //find the s1
        int s1 = (sum + target) / 2;
        //if the target is more than the sum of array then return 0
        //here we are checking that sum+target should be even
        if (target > sum || (sum + target) % 2 != 0)
            return 0;

        /*counting the zeros because if we put -, + sign anyway they are going
        to be the same. So if we have zeros then the number of subsets will 
        increase by 2^number of zeros. So we have to multiply to the result*/
        int zeros = count(nums.begin(), nums.end(), 0);

        return pow(2, zeros) * countOfsubsetSum(nums, nums.size(), s1);
    }

    int countOfsubsetSum(vector<int> &nums, int n, int sum)
    {
        vector<vector<int> > dp(n + 1, vector<int>(sum + 1));

        //initializing
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        //solving the small problems
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] <= j && nums[i - 1] != 0)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else //if(nums[i-1] > j || nums[i-1] == 0)
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};