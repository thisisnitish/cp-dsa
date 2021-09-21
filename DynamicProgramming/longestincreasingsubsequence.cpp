/*
Leetcode Question 300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/
*/

/*
We need to find maximum increasing subsequence length. In the brute-force approach, we can 
model this problem as -
1. If the current element is greater than the previous element, then we can either pick it or 
dont pick it because we may get a smaller element somewhere ahead which is greater than 
previous and picking that would be optimal. So we try both options.
2. If the current element is smaller or equal to previous element, it can't be picked.
*/

//Recursive
class Solution
{
public:
    //Time: O(2^N), Space: O(N)
    int lengthOfLIS(vector<int> &nums)
    {
        return helper(nums, -1, 0);
    }

    int helper(vector<int> &nums, int prevPos, int currPos)
    {
        //if the currPos equals size of array
        if (currPos == nums.size())
            return 0;

        //if we consider the element
        int take = 0;
        if (prevPos == -1 || nums[currPos] > nums[prevPos])
        {
            take = 1 + helper(nums, currPos, currPos + 1);
        }

        //if we don't consider the element
        int notTake = helper(nums, prevPos, currPos + 1);

        //return the max
        return max(take, notTake);
    }
};

//Recursive + Memoization
class Solution
{
public:
    //Time: O(N^2), Space: O(N^2)
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int> > memo(n + 1, vector<int>(n + 1, -1));
        return helper(nums, memo, -1, 0);
    }

    int helper(vector<int> &nums, vector<vector<int> > &memo, int prevPos, int currPos)
    {
        //if the currPos equals size of array
        if (currPos == nums.size())
            return 0;

        if (prevPos != -1 && memo[prevPos][currPos] != -1)
            return memo[prevPos][currPos];

        //if we consider the element
        int take = 0;
        if (prevPos == -1 || nums[currPos] > nums[prevPos])
        {
            take = 1 + helper(nums, memo, currPos, currPos + 1);
        }

        //if we don't consider the element
        int notTake = helper(nums, memo, prevPos, currPos + 1);

        //return the max
        if (prevPos != -1)
            return memo[prevPos][currPos] = max(take, notTake);
        return max(take, notTake);
    }
};

/*
Bottom Up Approach
We can solve it iteratively as well. Here, we use dp array where dp[i] denotes the LIS ending 
at index i. We can always pick a single element and hence all dp[i] will be initialized to 1.
For each element nums[i], if there's an smaller element nums[j] before it, the result will be 
maximum of current LIS length ending at i: dp[i], and LIS ending at that j + 1: dp[j] + 1. +1 
because we are including the current element and extending the LIS ending at j.
*/
class Solution
{
public:
    //Time: O(N^2), Space: O(N)
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int result = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};
