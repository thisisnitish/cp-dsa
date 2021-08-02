/*
Leetcode Question 1. Two Sum
https://leetcode.com/problems/two-sum/
*/

/*
The Brute Force will take O(n^2) as we have to traverse the array and check for every 
possible combination and then choose the index.
*/
//Two pass
class Solution
{
public:
    //Time: O(n), Space: O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            m[nums[i]] = i;

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (m.find(complement) != m.end())
            {
                if (m[complement] != i)
                {
                    ans.push_back(i);
                    ans.push_back(m[complement]);
                    break;
                }
            }
        }
        return ans;
    }
};

//Single pass
class Solution
{
public:
    //Time: O(n), Space: O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end())
            {
                if (mp[complement] != i)
                    return {mp[complement], i};
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};
