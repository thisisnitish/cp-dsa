/*
Leetcode Question 174. Dungeon Game
https://leetcode.com/problems/dungeon-game/
*/

/*
This question is the variation of the question Minimum Path Sum, first do that
then attempt this question, this will be very easy for you
*/

//Recursive
class Solution
{
public:
    //Time: O(2^N), Space: O(N)
    int result = 0;
    int calculateMinimumHP(vector<vector<int> > &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        return helper(dungeon, m, n, 0, 0);
        ;
    }

    int helper(vector<vector<int> > &dungeon, int m, int n, int x, int y)
    {
        if (x == m - 1 && y == n - 1)
            return dungeon[x][y] <= 0 ? abs(dungeon[x][y]) + 1 : 1;

        if (x >= m || y >= n)
            return INT_MAX;

        result = min(
                     helper(dungeon, m, n, x, y + 1),
                     helper(dungeon, m, n, x + 1, y)) -
                 dungeon[x][y];

        return result <= 0 ? 1 : result;
    }
};

//Recursive + Memoization, TopDown
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int result = 0;
    int calculateMinimumHP(vector<vector<int> > &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int> > memo(m + 1, vector<int>(n + 1, -1));
        return helper(dungeon, m, n, 0, 0, memo);
    }

    int helper(vector<vector<int> > &dungeon, int m, int n, int x, int y, vector<vector<int> > &memo)
    {
        if (x == m - 1 && y == n - 1)
            return dungeon[x][y] <= 0 ? abs(dungeon[x][y]) + 1 : 1;

        if (x >= m || y >= n)
            return INT_MAX;

        if (memo[x][y] != -1)
            return memo[x][y];

        result = min(
                     helper(dungeon, m, n, x, y + 1, memo),
                     helper(dungeon, m, n, x + 1, y, memo)) -
                 dungeon[x][y];

        return memo[x][y] = result <= 0 ? 1 : result;
    }
};
