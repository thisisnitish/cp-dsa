/*
Leetcode Question 55. Jump Game
https://leetcode.com/problems/jump-game/
*/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return false;
        int covered_position = 0;

        for (int i = 0; i <= covered_position && i < nums.size(); i++){
            if (covered_position < nums[i] + i)
                covered_position = nums[i] + i;

            if (covered_position >= nums.size() - 1)
                return true;
        }
        return false;
    }
};