/*
Leetcode Question 34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

class Solution
{
public
    //Time: O(logN)
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {findingIndex(nums, target, false), findingIndex(nums, target, true)};
    }
    int findingIndex(vector<int> &nums, int target, bool bound)
    {
        int low = 0, high = nums.size() - 1, result = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                result = mid;

                if (bound)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return result;
    }
};
