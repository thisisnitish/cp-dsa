/*
Leetcode Question 31. Next Permutation
https://leetcode.com/problems/next-permutation/
*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        //checking every element is sorted
        while (i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        if (i >= 0){
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]){
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }

    void reverse(vector<int> &nums, int start)
    {
        int i = start, j = nums.size() - 1;

        while (i < j){
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};