/*
Leetcode Question 162. Find Peak Element
https://leetcode.com/problems/find-peak-element/
*/

/*
The problem with this solution is, it will only work for the test case which is given in
leetcode. But, if you will use it to interviewbit for same question then it will not work.
The reason is very simple, here we are using mid-1 or mid+1 element as a frame of reference
in order to move in any direction.

But in order to make it work in interviewbit question we need to make mid element as a frame
of reference, then it will work. Rest everything is fine
Refer to the same problem on Interviewbit.
*/

// Solution 1
class Solution
{
public:
    // Time: O(logN), Space: O(1)
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

// Solution 2
class Solution
{
public:
    // Time: O(logN), Space: O(1)
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

//Interviewbit Solution
// Time: O(logN)
int Solution::solve(vector<int> &A)
{
    int n = A.size();

    // base case
    if (n == 1)
        return A[0];

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid > 0 && mid < n - 1)
        {
            // if we got the peak element
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
                return A[mid];
            else if (A[mid - 1] < A[mid])
                low = mid + 1;
            else if (A[mid + 1] < A[mid])
                high = mid - 1;
        }
        else if (mid == 0)
        {
            if (A[0] > A[1])
                return A[0];
            else
                return A[1];
        }
        else if (mid == n - 1)
        {
            if (A[n - 1] > A[n - 2])
                return A[n - 1];
            else
                return A[n - 2];
        }
    }
    return -1;
}

// Solution 3
class Solution
{
public:
    // Time: O(logN), Space: O(N)
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        int result = findPeak(nums, left, right);
        return result;
    }

    int findPeak(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return left;

        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1])
            return findPeak(nums, left, mid);
        else
            return findPeak(nums, mid + 1, right);
    }
};
