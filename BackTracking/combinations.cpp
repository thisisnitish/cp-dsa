/*
Leetcode Question 77. Combinations
https://leetcode.com/problems/combinations/
*/

class Solution
{
public:
    /*please attempt subset and subset2 
    questions so that you will grasp easily*/
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> combinations;
        vector<int> current; //to save the small lists
        findCombination(combinations, 1, n, k, current);
        return combinations;
    }

    void findCombination(vector<vector<int>> &combinations, int index, int n, int k, vector<int> &current)
    {

        /*we want the subsets of size k,
        if we have the subsets size is k then 
        add to the combinations array & return*/
        if (current.size() == k)
        {
            combinations.push_back(current);
            return;
        }

        for (int i = index; i <= n; i++)
        { // 1-------n
            current.push_back(i);
            findCombination(combinations, i + 1, n, k, current);
            current.pop_back();
        }
    }
};