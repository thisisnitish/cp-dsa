/*
Leetcode Question 33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        //first find the boundary according to the target then do regular binary search
        int length = nums.size();

        if (length == 0)
            return -1;

        int left = 0;
        int right = length - 1;

        //finding the pivot position
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        int start = left;
        left = 0;
        right = length - 1;

        //we got the perfect boundary for searching that element
        if (target >= nums[start] && target <= nums[right])
        {
            left = start;
        }
        else
            right = start;

        //regular binary search in the bounds
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
