/*
Leetcode Question 40. Combination Sum II
https://leetcode.com/problems/combination-sum-ii/
*/

//Solution 1
class Solution
{
public:
    //Time: O(2^N), Space: O(N)
    vector<vector<int> > combinations;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        helper(candidates, current, target, 0);
        return combinations;
    }

    void helper(vector<int> &candidates, vector<int> &current, int target, int idx)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            combinations.push_back(current);
            return;
        }
        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            current.push_back(candidates[i]);
            helper(candidates, current, target - candidates[i], i + 1);
            current.pop_back();
        }
    }
};

//Solution 2
//This will give you TLE
class Solution
{
public:
    vector<vector<int> > combinations;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        helper(candidates, current, target, 0);
        return combinations;
    }

    void helper(vector<int> &candidates, vector<int> &current, int target, int idx)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            if (find(combinations.begin(), combinations.end(), current) == combinations.end())
            {
                combinations.push_back(current);
            }
            return;
        }
        if (idx == candidates.size())
            return;
        auto op1 = current;
        auto op2 = current;
        op1.push_back(candidates[idx]);
        helper(candidates, op1, target - candidates[idx], idx + 1);
        helper(candidates, op2, target, idx + 1);
    }
};
