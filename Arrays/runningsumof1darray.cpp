/*
Leetcode Question 1480. Running Sum of 1d Array
https://leetcode.com/problems/running-sum-of-1d-array/
*/

//Solution 1
class Solution
{
public:
    //Time: O(n^2), Space: O(n)
    vector<int> runningSum(vector<int> &nums)
    {
        int sum = 0;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = 0; j <= i; j++)
            {
                sum += nums[j];
            }
            result.push_back(sum);
        }
        return result;
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(n), Space: O(n)
    vector<int> runningSum(vector<int> &nums)
    {
        int sum = 0;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            result.push_back(sum);
        }
        return result;
    }
};

//Solution 3
class Solution
{
public:
    //Time: O(n), Space: O(1)
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};
