/*
Leetcode Question 77. Combinations
https://leetcode.com/problems/combinations/
*/

//Solution 1 - TLE
class Solution
{
public:
    vector<vector<int> > combinations;
    vector<vector<int> > combine(int n, int k)
    {
        vector<int> ip;
        for (int i = 1; i <= n; i++)
            ip.push_back(i);
        vector<int> op;
        findCombination(ip, op, k);
        return combinations;
    }

    void findCombination(vector<int> ip, vector<int> op, int k)
    {
        if (ip.size() == 0)
        {
            if (op.size() == k)
                combinations.push_back(op);
            return;
        }
        auto op1 = op;
        auto op2 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        findCombination(ip, op1, k);
        findCombination(ip, op2, k);
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(n!/k!(n-k)!), Space: O(n!/k!(n-k)!)
    vector<vector<int> > combinations;
    vector<vector<int> > combine(int n, int k)
    {
        vector<int> current;
        findCombination(1, n, k, current);
        return combinations;
    }

    void findCombination(int index, int n, int k, vector<int> &current)
    {
        if (current.size() == k)
        {
            combinations.push_back(current);
            return;
        }

        for (int i = index; i <= n; i++)
        {
            current.push_back(i);
            findCombination(i + 1, n, k, current);
            current.pop_back();
        }
    }
};