/*
Leetcode Question 90. Subsets II
https://leetcode.com/problems/subsets-ii/
*/

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        vector<vector<int>> subset;

        if (nums.empty())
            return subset;

        /*main reason for sorting the elements is 
        putting the same elements together
        so that we will remove the duplicacy*/
        sort(nums.begin(), nums.end());
        vector<int> current;
        findSubsets(subset, 0, nums, current);
        return subset;
    }

    void findSubsets(vector<vector<int>> &subset, int index, vector<int> &nums, vector<int> &current)
    {
        subset.push_back(current);
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);
            findSubsets(subset, i + 1, nums, current);
            current.pop_back();
        }
    }
};