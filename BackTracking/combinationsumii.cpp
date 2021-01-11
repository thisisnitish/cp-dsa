/*
Leetcode Question 40. Combination Sum II
https://leetcode.com/problems/combination-sum-ii/
*/

class Solution
{
public:
    /*what i feel is this question is a combination of 
    subset, subset-ii and combination sum*/
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combination;
        vector<int> current;

        findCombination(combination, 0, candidates, current, target);
        return combination;
    }

    void findCombination(vector<vector<int>> &combination, int index, vector<int> &candidates, vector<int> &current, int target)
    {

        /* same as combination sum but here we don't
        have to use the same number again and again*/
        if (target < 0)
            return;
        if (target == 0)
        {
            combination.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {

            //handling duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            current.push_back(candidates[i]);
            findCombination(combination, i + 1, candidates, current, target - candidates[i]);
            current.pop_back();
        }
    }
};