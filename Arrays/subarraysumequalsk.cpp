/*
Leetcode Question 560. Subarray Sum Equals K
https://leetcode.com/problems/subarray-sum-equals-k/
*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if (mp[sum - k])
                count += mp[sum - k];

            mp[sum]++;
        }
        return count;
    }
};