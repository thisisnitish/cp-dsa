/*
Leetcode Question 189. Rotate Array
https://leetcode.com/problems/rotate-array/
*/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        reverse(nums, 0, nums.size() - 1);
        k = k % nums.size();     // k could be more than the size of the array
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }
    }
};