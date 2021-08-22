/*
Leetcode Question 47. Permutations II
https://leetcode.com/problems/permutations-ii/
*/

class Solution
{
public:
    //Time: O(N.N! + NlogN), Space: O(N)
    vector<vector<int> > permutations;
    vector<vector<int> > permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        generatePermutations(nums, 0);
        return permutations;
    }

    void generatePermutations(vector<int> nums, int idx)
    {
        if (idx == nums.size())
        {
            permutations.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            if (idx != i && nums[i] == nums[idx])
                continue;
            swap(nums[idx], nums[i]);
            generatePermutations(nums, idx + 1);
            // swap(nums[idx], nums[i]);
        }
    }
};
