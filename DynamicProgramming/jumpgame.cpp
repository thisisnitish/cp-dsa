/*
Leetcode Question 55. Jump Game
https://leetcode.com/problems/jump-game/
*/

/*
This solution can be done in two ways.
1. One way is to focus on reachability i.e. how much reachable you are. Or is any
index is reachable to the last index or not.
2. Other way is to focus on number of jumps, i.e. any jump can reach you to the last
index or not.

Below, I've done in the first way because it is pretty easy and intuitive, but the
second way can also be done, with some minute changes to the below code.
*/

// Recursive
class Solution
{
public:
    // Time: Exponential
    bool canJumpImpl(vector<int> &nums, int idx)
    {
        // base case
        if (idx == nums.size() - 1)
            return true;

        for (int i = idx + 1; i <= nums[idx] + idx; i++)
        {
            if (canJumpImpl(nums, i))
                return true;
        }
        return false;
    }
    bool canJump(vector<int> &nums)
    {
        return canJumpImpl(nums, 0);
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: Exponential
    bool canJumpImpl(vector<int> &nums, int idx, vector<int> &memo)
    {
        // base case
        if (idx == nums.size() - 1)
            return true;

        if (memo[idx] != -1)
            return memo[idx];

        for (int i = idx + 1; i <= nums[idx] + idx; i++)
        {
            if (canJumpImpl(nums, i, memo))
                return memo[idx] = true;
        }
        return memo[idx] = false;
    }
    bool canJump(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        return canJumpImpl(nums, 0, memo);
    }
};

/*
It can be done using greedy approach as well.
*/

class Solution
{
public:
    // Time: O(N), Space: O(1)
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 0)
            return false;
        int covered_position = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > covered_position)
                return false;
            covered_position = max(covered_position, nums[i] + i);
        }
        return true;
    }
};
