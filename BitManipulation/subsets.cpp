/*
Leetcode Question 78. Subsets
https://leetcode.com/problems/subsets/
*/

class Solution
{
public:
    //O(n^2)
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;

        for (int i = 0; i < (1 << nums.size()); i++)
        { // 1<<nums.size() => 2^nums.size();
            vector<int> temp;
            for (int j = 0; j < nums.size(); j++)
            { //this loop for positions for a number
                if (i & (1 << j))
                { // check a bit is set or unset
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};