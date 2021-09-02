/*
Leetcode Question 1695. Maximum Erasure Value
https://leetcode.com/problems/maximum-erasure-value/
*/

/*
This question says erase the subarray containing unique elements. And the score you get is 
sum of its elements. Basically this problem reduced to finding the subarray having all 
unique elements and also having maximum sum.
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int result = INT_MIN, sum = 0;

        while (j < nums.size())
        {
            //Calculation I
            sum += nums[j];
            mp[nums[j]]++;
            if (mp.size() < j - i + 1)
            {
                while (mp.size() < j - i + 1)
                {
                    sum = sum - nums[i];
                    mp[nums[i]]--;

                    if (mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }
                j++;
            }
            else if (mp.size() == j - i + 1)
            {
                //Calculation II
                result = max(result, sum);
                j++;
            }
        }
        return result;
    }
};
