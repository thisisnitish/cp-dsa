/*
Leetcode Question 1463. Cherry Pickup II
https://leetcode.com/problems/cherry-pickup-ii/
*/

class Solution
{
public:
    // Time: O(m*n^2)
    vector<vector<vector<int>>> memo;
    int cherryPickupImpl(vector<vector<int>> &grid, int x, int y1, int y2)
    {

        if (y1 < 0 || y1 >= grid[0].size() || y1 < 0 || y2 >= grid[0].size())
            return 0;

        if (memo[x][y1][y2] != -1)
            return memo[x][y1][y2];

        int sum = 0;
        if (y1 != y2)
        {
            sum += grid[x][y1] + grid[x][y2];
        }
        else
        {
            sum += grid[x][y1];
        }

        if (x != grid.size() - 1)
        {
            int localMax = 0;
            for (int tempY1 = y1 - 1; tempY1 <= y1 + 1; tempY1++)
            {
                for (int tempY2 = y2 - 1; tempY2 <= y2 + 1; tempY2++)
                {
                    localMax = max(localMax,
                                   cherryPickupImpl(grid, x + 1, tempY1, tempY2));
                }
            }
            sum += localMax;
        }
        return memo[x][y1][y2] = sum;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        memo.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return cherryPickupImpl(grid, 0, 0, n - 1);
    }
};
