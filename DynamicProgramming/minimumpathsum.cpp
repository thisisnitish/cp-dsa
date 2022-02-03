/*
Leetcode Question 64. Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/
*/

// Recursive
class Solution
{
public:
    // Time: O(2^m*n), Space: O(2^m*n)
    int minPathSum(vector<vector<int> > &grid)
    {
        int m = grid.size();    // rows
        int n = grid[0].size(); // cols;
        return helper(grid, m, n, 0, 0);
    }

    int helper(vector<vector<int> > &grid, int m, int n, int x, int y)
    {
        // Base condition
        if (x == m - 1 && y == n - 1)
            return grid[x][y];
        if (x >= m || y >= n)
            return INT_MAX;

        // recursive calls and checking for the minimum path
        return grid[x][y] +
               min(helper(grid, m, n, x, y + 1), helper(grid, m, n, x + 1, y));
    }
};

// Recursive + Memoization, BottomUp
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    vector<vector<int> > memo;
    int minPathSum(vector<vector<int> > &grid)
    {
        int m = grid.size();    // rows
        int n = grid[0].size(); // cols;

        memo.resize(m, vector<int>(n, -1));
        return helper(grid, m, n, 0, 0);
    }

    int helper(vector<vector<int> > &grid, int m, int n, int x, int y)
    {
        // Base condition
        if (x == m - 1 && y == n - 1)
            return grid[x][y];
        if (x >= m || y >= n)
            return INT_MAX;
        if (memo[x][y] != -1)
            return memo[x][y];

        // recursive calls and checking for the minimum path
        memo[x][y] = grid[x][y] +
                     min(helper(grid, m, n, x, y + 1), helper(grid, m, n, x + 1, y));
        return memo[x][y];
    }
};

// TopDown
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int minPathSum(vector<vector<int> > &grid)
    {
        int m = grid.size(); // rows

        if (m == 0)
            return 0;

        int n = grid[0].size(); // cols;

        vector<vector<int> > dp(m, vector<int>(n, 0));

        // fill the first value
        dp[0][0] = grid[0][0];

        // initializing the first row
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];

        // initializing the first column
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        // solving the subproblems
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

// TopDown Space Optimze
class Solution
{
public:
    // Time: O(m*n), Space: O(1)
    int minPathSum(vector<vector<int> > &grid)
    {
        int m = grid.size(); // rows

        if (m == 0)
            return 0;

        int n = grid[0].size(); // cols;

        // fill the first value
        grid[0][0] = grid[0][0];

        // initializing the first row
        for (int j = 1; j < n; j++)
            grid[0][j] = grid[0][j - 1] + grid[0][j];

        // initializing the first column
        for (int i = 1; i < m; i++)
            grid[i][0] = grid[i - 1][0] + grid[i][0];

        // solving the subproblems
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
