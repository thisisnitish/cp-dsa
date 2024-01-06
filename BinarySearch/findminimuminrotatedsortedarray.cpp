/*
Leetcode Question 153. Find Minimum in Rotated Sorted Array
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

// Solution 1
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

        // base case i.e. if the array is sorted already
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

// Solution 2
class Solution
{
public:
    // Time: O(logN), Space: O(1)
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        if (nums[low] < nums[high])
            return nums[low];

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            // minimum element will always be lesser than either side of element
            if (nums[prev] >= nums[mid] && nums[mid] <= nums[next])
                return nums[mid];

            // move to unsorted half because it only contains
            // the minimum element
            if (nums[0] <= nums[mid])
                low = mid + 1;
            else if (nums[mid] <= nums[n - 1])
                high = mid - 1;
        }

        return -1;
    }
};
