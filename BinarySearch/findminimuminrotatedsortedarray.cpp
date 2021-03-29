/*
Leetcode Question 153. Find Minimum in Rotated Sorted Array
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

class Solution
{
public:
    /*the basic idea is to apply binary search algorithm,
    first check for if first element is greater than the last
    element then return the first element because array is already sorted
    but if this is not the case then find the middle element and check if 
    it is less than the right, if yes then move towards the left side of 
    array else move towards the right side of the array. Time: O(logN),
    Space: O(1)*/
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        //base case i.e. if the array is sorted already
        if (nums[left] < nums[right])
            return nums[left];

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
