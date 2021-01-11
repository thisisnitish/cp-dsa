/*
Leetcode Question 39. Combination Sum
https://leetcode.com/problems/combination-sum/
*/

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> combination;
        vector<int> current; //to save the small lists
        findCombination(combination, 0, candidates, current, target);
        return combination;
    }

    void findCombination(vector<vector<int>> &combination, int index, vector<int> &candidates, vector<int> &current, int target)
    {

        /* the basic idea is using recursion for every
         possible combination and subtracting a number over and over
         if target < 0 return because not any use of it else if target == 0
         push the subset in set and return*/
        if (target < 0)
            return;
        else if (target == 0)
        {
            combination.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            current.push_back(candidates[i]);
            /* In subset problem we didn't used the same number again 
            but this problem allowing us to do this */
            findCombination(combination, i, candidates, current, target - candidates[i]);
            current.pop_back();
        }
    }
};