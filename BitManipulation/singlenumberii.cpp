/*
Leetcode Question 137. Single Number II
https://leetcode.com/problems/single-number-ii/
*/

//Solution 1
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto n : nums)
        {
            mp[n]++;
        }

        for (auto [k, v] : mp)
        {
            if (v == 1)
                return k;
        }
        return -1;
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(NlogN), Space: O(N)
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        sort(nums.begin(), nums.end());

        //base conditions
        //desired element could be at first position or last position
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        for (int i = 1; i < n - 1; i++)
        {
            //if the condition is true then nums[i] will be the unique number
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                return nums[i];
        }
        return -1;
    }
};

//Solution 3
class Solution
{
public:
    //Time: O(N), Space: O(1)
    int singleNumber(vector<int> &nums)
    {
        /*ones store the number occurs only one time and twos 
        stores the number occurs only two times*/
        int ones = 0, twos = 0;

        for (auto n : nums)
        {
            ones = (ones ^ n) & (~twos);
            twos = (twos ^ n) & (~ones);
        }
        return ones;
    }
};
