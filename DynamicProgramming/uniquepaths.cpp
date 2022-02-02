/*
Leetcode Question 62. Unique Paths
https://leetcode.com/problems/unique-paths/
*/

/*
It's very simple question, you need to explore every path to reach the end of the
grid. Also, since it is asking number of paths, so you need to add all the choices
that you explore.
*/
// Recursive
class Solution
{
public:
    // Time: O(2^m*n), Space: O(2^m*n)
    int numberOfUniquePaths(int x, int y, int m, int n)
    {
        // base case
        if (x >= m or y >= n)
            return 0;
        if (x == m - 1 and y == n - 1)
            return 1;

        return numberOfUniquePaths(x, y + 1, m, n) + numberOfUniquePaths(x + 1, y, m, n);
    }

    int uniquePaths(int m, int n)
    {
        return numberOfUniquePaths(0, 0, m, n);
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int numberOfUniquePaths(int x, int y, int m, int n, vector<vector<int> > &memo)
    {
        // base case
        if (x >= m or y >= n)
            return 0;
        if (x == m - 1 and y == n - 1)
            return memo[x][y] = 1;

        if (memo[x][y] != -1)
            return memo[x][y];

        memo[x][y] = numberOfUniquePaths(x, y + 1, m, n, memo) +
                     numberOfUniquePaths(x + 1, y, m, n, memo);
        return memo[x][y];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int> > memo(m, vector<int>(n, -1));
        return numberOfUniquePaths(0, 0, m, n, memo);
    }
};

// Tabulation
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int uniquePaths(int m, int n)
    {
        vector<vector<int> > dp(m, vector<int>(n, 0));

        /*
        This is a base case, if m = 0 or n = 0 then we have only one choice
        to move in only direction. Otherwise we will have two choices to move
        downward and rightward.
        */

        // initialization
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 1;
            }
        }

        // solving the sub-problems
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
