/*
Leetcode Question 63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/
*/

//Recusrive
class Solution
{
public:
    //Time: O(2^n), Space: O(n)
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();    //rows
        int n = obstacleGrid[0].size(); //columns
        return helper(obstacleGrid, m, n, 0, 0);
    }

    int helper(vector<vector<int> > &obstacleGrid, int m, int n, int x, int y)
    {
        if (x >= m || y >= n || obstacleGrid[x][y] == 1)
            return 0;
        if (x == m - 1 && y == n - 1)
            return 1;

        return helper(obstacleGrid, m, n, x + 1, y) + helper(obstacleGrid, m, n, x, y + 1);
    }
};

//Memoization - TopDown approach
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();    //rows
        int n = obstacleGrid[0].size(); //columns
        vector<vector<int> > memo(m, vector<int>(n, -1));
        return helper(obstacleGrid, m, n, 0, 0, memo);
    }

    int helper(vector<vector<int> > &obstacleGrid, int m, int n, int x, int y, vector<vector<int> > &memo)
    {
        if (x >= m || y >= n || obstacleGrid[x][y] == 1)
            return 0;
        if (x == m - 1 && y == n - 1)
            return 1;

        if (memo[x][y] != -1)
            return memo[x][y];

        memo[x][y] = helper(obstacleGrid, m, n, x + 1, y, memo) +
                     helper(obstacleGrid, m, n, x, y + 1, memo);

        return memo[x][y];
    }
};

//BottomUp
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();    //rows
        int n = obstacleGrid[0].size(); //columns
        return helper(obstacleGrid, m, n);
    }

    int helper(vector<vector<int> > &obstacleGrid, int m, int n)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int> > dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        //filling the first column
        for (int i = 1; i < m; i++)
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i - 1][0];

        //filling the first row
        for (int j = 1; j < n; j++)
            if (obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j - 1];

        //filling the matrix
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
