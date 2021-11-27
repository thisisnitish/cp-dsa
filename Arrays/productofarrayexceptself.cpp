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
    // Time: O(N), Space: O(1)
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;
        int totalProduct = 1, zeroCount = 0;

        // finding the total product and counting zeros
        for (auto n : nums)
        {
            if (n == 0)
                zeroCount++;
            else
                totalProduct = totalProduct * n;
        }

        for (auto n : nums)
        {
            if (n == 0)
            {
                if (zeroCount != 1)
                    ans.push_back(0);
                else
                    ans.push_back(totalProduct);
            }
            else
            {
                if (zeroCount == 0)
                    ans.push_back(totalProduct / n);
                else
                    ans.push_back(0);
            }
        }
        return ans;
    }
};

// Solution 3
class Solution
{
public:
    // Time: O(N), Space: O(1)
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int temp = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = temp;
            temp = temp * nums[i];
        }

        temp = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * temp;
            temp = temp * nums[i];
        }
        return ans;
    }
};
