/*
Leetcode Question 63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/
*/

/*
This is an exetension of unique path question. Here also, we need to explore all the
paths. But, one thing to notice here is, we have an obstacle in a grid and we need to
by pass that obstacle in order to reach the target.

Also,If we design the recursive solution, we will find out that, it has so many
repetitive paths, that is a sure hint to move towards the DP solution.
*/

// Recursive
class Solution
{
public:
    // Time: O(2^m*n), Space: O(2^m*n)
    int countUniquePaths(vector<vector<int> > &obstacleGrid, int x, int y, int m, int n)
    {
        // base case
        if (x >= m || y >= n)
            return 0;
        if (obstacleGrid[x][y] == 1)
            return 0;
        if (x == m - 1 && y == n - 1)
            return 1;

        return countUniquePaths(obstacleGrid, x + 1, y, m, n) +
               countUniquePaths(obstacleGrid, x, y + 1, m, n);
    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return countUniquePaths(obstacleGrid, 0, 0, m, n);
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    vector<vector<int> > memo;
    int countUniquePaths(vector<vector<int> > &obstacleGrid, int x, int y, int m, int n)
    {
        // base case
        if (x >= m || y >= n)
            return 0;
        if (obstacleGrid[x][y] == 1)
            return memo[x][y] = 0;
        if (x == m - 1 && y == n - 1)
            return memo[x][y] = 1;

        if (memo[x][y] != -1)
            return memo[x][y];

        memo[x][y] = countUniquePaths(obstacleGrid, x + 1, y, m, n) +
                     countUniquePaths(obstacleGrid, x, y + 1, m, n);
        return memo[x][y];
    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        memo.resize(m, vector<int>(n, -1));

        return countUniquePaths(obstacleGrid, 0, 0, m, n);
    }
};

// Tabulation
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int> > dp(m, vector<int>(n, 0));

        // initialization
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] != 1)
                dp[0][j] = 1;
            else
                break;
        }

        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] != 1)
                dp[i][0] = 1;
            else
                break;
        }

        // solving the sub problems
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }

        return dp[m - 1][n - 1];
    }
};
