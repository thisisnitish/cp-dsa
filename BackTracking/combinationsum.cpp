/*
Leetcode Question 39. Combination Sum
https://leetcode.com/problems/combination-sum/
*/

//Solution 1
class Solution
{
public:
    vector<vector<int> > combinations;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<int> current;
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
            current.push_back(candidates[i]);
            helper(candidates, current, target - candidates[i], i);
            current.pop_back();
        }
    }
};

//Solution 2
class Solution
{
public:
    vector<vector<int> > combinations;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<int> current;
        helper(candidates, current, target, 0);
        return combinations;
    }

    void helper(vector<int> &candidates, vector<int> &op, int target, int idx)
    {
        if (target == 0)
        {
            combinations.push_back(op);
            return;
        }
        if (idx == candidates.size() || target < 0)
            return;

        auto op1 = op;
        auto op2 = op;
        op1.push_back(candidates[idx]);
        helper(candidates, op1, target - candidates[idx], idx);
        helper(candidates, op2, target, idx + 1);
    }
};
