/*
Leetcode Question 209. Minimum Size Subarray Sum
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        //two pointer approach
        int left = 0;
        int sum = 0;
        int result = INT_MAX;

        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];

            while (sum >= s){
                result = min(result, i + 1 - left);
                sum -= nums[left++];
            }
        }
        if (result != INT_MAX)
            return result;
        else
            return 0;
    }
};