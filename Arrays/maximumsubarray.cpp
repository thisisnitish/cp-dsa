/*
Leetcode Question 53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/
*/

// Brute Froce
class Solution
{
public:
    // Time: O(N^2), Space: O(1)
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};

// Kadane's Algorithm - Dynamic Programming
class Solution
{
public:
    // Time: O(N), Space: O(1)
    int maxSubArray(vector<int> &nums)
    {
        int maxSoFar = nums[0];
        int globalMax = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            maxSoFar = max(nums[i], nums[i] + maxSoFar);
            globalMax = max(globalMax, maxSoFar);
        }
        return globalMax;
    }
};
