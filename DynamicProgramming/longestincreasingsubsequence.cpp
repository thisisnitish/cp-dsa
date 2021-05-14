/*
Leetcode Question 300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/
*/

//Recursive
class Solution
{
public:
    /*Time: O(2^N), Space: O(N)*/
    int lengthOfLIS(vector<int> &nums)
    {
        return helper(nums, -1, 0);
    }

    int helper(vector<int> &nums, int prevPosition, int currPosition)
    {
        if (currPosition == nums.size())
            return 0;

        int taken = 0, notTaken;
        if (prevPosition == -1 || nums[currPosition] > nums[prevPosition])
        {
            taken = 1 + helper(nums, currPosition, currPosition + 1);
        }

        notTaken = helper(nums, prevPosition, currPosition + 1);
        return max(taken, notTaken);
    }
};

//Memoized - BottomUp
class Solution
{
public:
    /*Time: O(N*N), Space: O(N*N)*/
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
        return helper(nums, -1, 0, dp);
    }

    int helper(vector<int> &nums, int prevPosition, int currPosition, vector<vector<int> > &dp)
    {
        if (currPosition == nums.size())
            return 0;

        if (prevPosition != -1 && dp[prevPosition][currPosition] != -1)
            return dp[prevPosition][currPosition];

        int taken = 0, notTaken;
        if (prevPosition == -1 || nums[currPosition] > nums[prevPosition])
        {
            taken = 1 + helper(nums, currPosition, currPosition + 1, dp);
        }

        notTaken = helper(nums, prevPosition, currPosition + 1, dp);

        if (prevPosition != -1)
            return dp[prevPosition][currPosition] = max(taken, notTaken);
        return max(taken, notTaken);
    }
};
