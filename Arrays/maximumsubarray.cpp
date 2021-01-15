/*
Leetcode Question 53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/
*/

//Soultion 1
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        
        int curr_max = nums[0];
        int global_max = nums[0];
        for (int i = 1; i < nums.size(); i++){
            curr_max = max(curr_max + nums[i], nums[i]);
            global_max = max(curr_max, global_max);
        }
        return global_max;
    }
};

//Soutlion 2
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //But the problem with this solution is, it will not handle the negative numbers
        int curr_max = 0, global_max = 0;
        for(int i=0; i<nums.size(); i++){
            curr_max = curr_max + nums[i];
            if(curr_max < 0) curr_max = 0;
            else if(global_max < curr_max) global_max = curr_max;
        }
        return global_max;
    }
};