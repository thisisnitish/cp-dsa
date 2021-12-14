/*
Leetcode Question 1306. Jump Game III
https://leetcode.com/problems/jump-game-iii/
*/

class Solution
{
public:
    bool helper(vector<int> &arr, vector<int> &visited, int i)
    {
        if (i < 0 or i >= arr.size() or visited[i])
            return false;
        if (arr[i] == 0)
            return true;
        visited[i] = true;

        bool ans = helper(arr, visited, i + arr[i]) || helper(arr, visited, i - arr[i]);
        return ans;
    }

    bool canReach(vector<int> &arr, int start)
    {
        vector<int> visited(arr.size(), false);
        return helper(arr, visited, start);
    }
};
