/*
Leetcode Question 980. Unique Paths III
https://leetcode.com/problems/unique-paths-iii/
*/

class Solution
{
public:
    // Time: O(3^(m*n)), Space: O(m*n)
    int emptyCells = 1;
    int uniquePathsIII(vector<vector<int> > &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int startX, startY;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    startX = i, startY = j;
                if (grid[i][j] == 0)
                    emptyCells++;
            }
        }

        return helper(grid, startX, startY, m, n, 0);
    }

    int helper(vector<vector<int> > &grid, int x, int y, int m, int n, int cell)
    {
        if (x >= m || y >= n || x < 0 || y < 0 || grid[x][y] == -1)
            return 0;
        if (grid[x][y] == 3)
            return 0;

        // when you hit the ending square
        if (grid[x][y] == 2)
        {
            if (cell == emptyCells)
                return 1;
            else
                return 0;
        }
        grid[x][y] = 3; // mark it visited

        int count = helper(grid, x + 1, y, m, n, cell + 1) +
                    helper(grid, x - 1, y, m, n, cell + 1) +
                    helper(grid, x, y + 1, m, n, cell + 1) +
                    helper(grid, x, y - 1, m, n, cell + 1);

        grid[x][y] = 0; // mark it univisted
        return count;
    }
};
