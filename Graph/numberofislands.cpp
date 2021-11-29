/*
Leetcode Question 200. Number of Islands
https://leetcode.com/problems/number-of-islands/
*/

// Solution 1
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int findIslands(vector<vector<char> > &grid, vector<vector<bool> > &visited, int x, int y)
    {
        if (x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y])
            return 0;

        visited[x][y] = true;

        findIslands(grid, visited, x + 1, y);
        findIslands(grid, visited, x - 1, y);
        findIslands(grid, visited, x, y + 1);
        findIslands(grid, visited, x, y - 1);
        return 1;
    }
    int numIslands(vector<vector<char> > &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool> > visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (findIslands(grid, visited, i, j))
                    ans++;
            }
        }
        return ans;
    }
};

// Solution 2
class Solution
{
public:
    // Time: O(m*n), Space: O(1)
    void findIslands(vector<vector<char> > &grid, int x, int y)
    {
        if (x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
            return;

        grid[x][y] = '0';

        findIslands(grid, x + 1, y);
        findIslands(grid, x - 1, y);
        findIslands(grid, x, y + 1);
        findIslands(grid, x, y - 1);
    }

    int numIslands(vector<vector<char> > &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool> > visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    findIslands(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
