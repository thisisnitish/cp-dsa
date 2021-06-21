/*
Leetcode Question 1. Two Sum
https://leetcode.com/problems/two-sum/
*/

class Solution
{
public:
    //Time: O(n), Space: O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            m.insert({nums[i], i});

        vector<int> ans;

        for (int i = 0; i < n; i++){
            int complement = target - nums[i];
            if (m.find(complement) != m.end()){
                if (m[complement] != i){
                    ans.push_back(i);
                    ans.push_back(m[complement]);
                    break;
                }
            }
        }
        return ans;
    }
};