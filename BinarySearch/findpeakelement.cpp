/*
Leetcode Question 162. Find Peak Element
https://leetcode.com/problems/find-peak-element/
*/

//Solution 1
class Solution
{
public:
    //Time: O(logN), Space: O(1)
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;

        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (mid > 0 && mid < nums.size() - 1)
            {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                    return mid;
                else if (nums[mid - 1] > nums[mid])
                    high = mid - 1;
                else if (nums[mid + 1] > nums[mid])
                    low = mid + 1;
            }
            else if (mid == 0)
            {
                if (nums[0] > nums[1])
                    return 0;
                else
                    return 1;
            }
            else if (mid == nums.size() - 1)
            {
                if (nums[nums.size() - 1] > nums[nums.size() - 2])
                    return nums.size() - 1;
                else
                    return nums.size() - 2;
            }
        }
        return -1;
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(logN), Space: O(1)
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2)
            return nums[0] > nums[1] ? 0 : 1;

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid - 1] >= nums[mid])
                high = mid - 1;
            else if (nums[mid + 1] > nums[mid])
                low = mid + 1;
        }
        if (nums[0] > nums[1])
            return 0;
        else if (nums[n - 1] > nums[n - 2])
            return n - 1;
        return -1;
    }
};
