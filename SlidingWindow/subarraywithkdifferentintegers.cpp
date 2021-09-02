/*
Leetcode Question 992. Subarrays with K Different Integers
https://leetcode.com/problems/subarrays-with-k-different-integers/
*/

/*
Since the question says that we need exactly k elements so we need to remove less than k
elements.
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int helper(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int count = 0;
        while (j < nums.size())
        {
            mp[nums[j]]++;

            if (mp.size() <= k)
            {
                count += j - i + 1;
                j++;
            }
            else if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }
                count += j - i + 1;
                j++;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
