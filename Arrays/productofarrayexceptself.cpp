/*
Leetcode Question 238. Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/
*/

// Solution 1
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                    continue;
                ans[i] = ans[i] * nums[j];
            }
        }
        return ans;
    }
};

// Solution 2
class Solution
{
public:
    // Time: O(N), Space: O(N)
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // for left: left[i] = left[i-1] * nums[i-1]
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // for right: right[i] = right[i+1] * nums[i+1]
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        // now multiply both array elements
        for (int i = 0; i < n; i++)
        {
            nums[i] = left[i] * right[i];
        }
        return nums;
    }
};

// Solution 3
class Solution
{
public:
    // Time: O(N), Space: O(1)
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 1);

        for (int i = 1; i < n; i++)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int product = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            result[i] = result[i] * product;
            product = product * nums[i];
        }

        return result;
    }
};
