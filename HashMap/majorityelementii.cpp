/*
Leetcode Question 229. Majority Element II
https://leetcode.com/problems/majority-element-ii/
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        vector<int> result;

        for (auto x : nums){
            mp[x]++;
        }

        for (auto item : mp){
            if (item.second > nums.size() / 3){
                result.push_back(item.first);
            }
        }
        return result;
    }
};