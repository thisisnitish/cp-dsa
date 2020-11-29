/*
Leetcode Question 283. Move Zeroes
https://leetcode.com/problems/move-zeroes/ 
*/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int lastNonzero = 0, current = 0; current < nums.size(); current++){
            if (nums[current] != 0){
                swap(nums[lastNonzero], nums[current]);
                lastNonzero++;
            }
        }
    }
};