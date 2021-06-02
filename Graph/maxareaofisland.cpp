/*
Leetcode Question 695. Max Area of Island
https://leetcode.com/problems/max-area-of-island/
*/

/*
Consider the entire grid as a graph representation and think of the group of 1's as a 
connected components so you can simply apply dfs in all the 4 directions from a particular
cell in the grid. Make sure you don't visited the same cell again, to overcome this make a 
2d array visited to keep track of the cell which is already visited.
*/

class Solution
{
public:
    //Time: O(r*c), Space: O(r*c)
    int maxArea(int r, int c, vector<vector<int> > &grid, vector<vector<bool> > &visited)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
            visited[r][c] || grid[r][c] == 0)
        {
            return 0;
        }

        visited[r][c] = true;
        return (1 + maxArea(r + 1, c, grid, visited) + maxArea(r, c + 1, grid, visited) +
                maxArea(r - 1, c, grid, visited) + maxArea(r, c - 1, grid, visited));
    }
    int maxAreaOfIsland(vector<vector<int> > &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        //to keep the track of all the squares which are visited or not
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));

        int result = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                result = max(result, maxArea(r, c, grid, visited));
            }
        }
        return result;
    }
};

//Space Optimized
class Solution
{
public:
    //Time: O(r*c), Space: O(1)
    int maxArea(int r, int c, vector<vector<int> > &grid)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
        {
            return 0;
        }

        grid[r][c] = 0;
        return (1 + maxArea(r + 1, c, grid) + maxArea(r, c + 1, grid) +
                maxArea(r - 1, c, grid) + maxArea(r, c - 1, grid));
    }
    int maxAreaOfIsland(vector<vector<int> > &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int result = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == 1)
                    result = max(result, maxArea(r, c, grid));
            }
        }
        return result;
    }
};
