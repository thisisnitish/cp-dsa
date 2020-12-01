/*
Leetcode Question 164. Maximum Gap
https://leetcode.com/problems/maximum-gap/
*/

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        sort(nums.begin(), nums.end());
        int global_max_diff = 0, curr_max_diff = 0;

        int i = 0;
        while (i < nums.size() - 1){
            curr_max_diff = abs(nums[i] - nums[i + 1]);
            if (global_max_diff < curr_max_diff)
                global_max_diff = curr_max_diff;
            curr_max_diff = 0;
            i++;
        }
        return global_max_diff;
    }
};