/*
Leetcode Question 62. Unique Paths
https://leetcode.com/problems/unique-paths/
*/

//Recursive
class Solution
{
public:
    //Time: O(2^n), Space: O(n)
    int countPath(int x, int y, int m, int n)
    {
        //base condition
        if (x >= m || y >= n)
            return 0;

        if (x == m - 1 && y == n - 1)
            return 1;

        //counting the number of ways
        return countPath(x + 1, y, m, n) + countPath(x, y + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        return countPath(0, 0, m, n);
    }
};

//Memoization, TopDown Approach
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int countPath(int x, int y, int m, int n, vector<vector<int> > &memo)
    {
        if (x >= m || y >= n)
            return 0;

        if (x == m - 1 && y == n - 1)
            return 1;

        if (memo[x][y] != -1)
            return memo[x][y];

        memo[x][y] = countPath(x + 1, y, m, n, memo) + countPath(x, y + 1, m, n, memo);
        return memo[x][y];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int> > memo(m, vector<int>(n, -1));
        return countPath(0, 0, m, n, memo);
    }
};

//Bottom Up Approach
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int uniquePaths(int m, int n)
    {
        vector<vector<int> > dp(m, vector<int>(n, 0));

        //initializing the first row and column
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 1;

        //solving the subproblems
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};
