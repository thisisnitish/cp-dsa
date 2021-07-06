/*
Leetcode Question 169. Majority Element
https://leetcode.com/problems/majority-element/
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (auto x : nums){
            mp[x]++;
        }

        for (auto item : mp){
            if (item.second > nums.size() / 2){
                return item.first;
            }
        }
        return 0;
    }
};