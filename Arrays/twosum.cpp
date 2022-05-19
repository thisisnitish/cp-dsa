/*
Leetcode Question 1. Two Sum
https://leetcode.com/problems/two-sum/
*/

/*
Brute Force will be O(n^2), but then we cannot do it as it will not be an efficient
algorithm to use.
Further optimization I decided was O(nlogn). In this case, we can reduce the second
loop from n to logn making the entire time complexity O(nlogn).
But still it is not enough, We have to make it to O(n). To do so, we can use hashing
for this and store the index of each element.
While traversing the array, we can check for the complement in the hash-map and
check whether the index of complement and index of nums[i] is different or not.

This is a really good problem to start algorithm skills. I've done brute force. I
believe, It is self understood. But, In an interview, we have to start from the
Brute Force no matter how well you know the question.
*/

// Two Pass
class Solution
{
public:
    // Time: O(N), Space: O(N)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end())
            {
                if (mp[complement] != i)
                    return {i, mp[complement]};
            }
        }
        return {};
    }
};

// Single Pass
class Solution
{
public:
    // Time: O(N), Space: O(N)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end())
            {
                if (mp[complement] != i)
                    return {i, mp[complement]};
            }
            else
                mp[nums[i]] = i;
        }
        return {};
    }
};
