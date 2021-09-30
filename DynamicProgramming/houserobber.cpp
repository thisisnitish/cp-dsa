/*
Leetcode Question 198. House Robber
https://leetcode.com/problems/house-robber/
*/

//Recursive
class Solution
{
public:
    //Time: O(2^N), Space: O(N)
    int rob(vector<int> &nums)
    {
        return robHouse(nums, nums.size());
    }

    int robHouse(vector<int> &nums, int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int position1 = nums[n - 1] + robHouse(nums, n - 2);
        int position2 = robHouse(nums, n - 1);
        return max(position1, position2);
    }
};

//Recursive + Memoization - Bottom Up
class Solution
{
public:
    //Time: O(N), Space: O(N)
    vector<int> memo;
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        memo.resize(nums.size() + 1, -1);
        return robHouse(nums, nums.size());
    }

    int robHouse(vector<int> &nums, int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (memo[n] != -1)
            return memo[n];

        /*
            here I'm at a start position. Now, I've two choices, I've to go to the alternate
            house to rob and also I can start from the next house as well. After that, we
            can take the maximum of both the approaches
        */
        int position1 = nums[n - 1] + robHouse(nums, n - 2);
        int position2 = robHouse(nums, n - 1);
        return memo[n] = max(position1, position2);
    }
};
