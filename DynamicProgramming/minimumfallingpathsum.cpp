/*
Leetcode Question 931. Minimum Falling Path Sum
https://leetcode.com/problems/minimum-falling-path-sum/
*/

// Recursive
class Solution
{
public:
    // Time: O(n*3^n), Space: O(3^n)
    int minFallingPathSum(vector<vector<int> > &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = INT_MAX;

        // can start from every point in the first row
        for (int i = 0; i < n; i++)
        {
            result = min(result, findSum(matrix, 0, i));
        }
        return result;
    }

    int findSum(vector<vector<int> > &matrix, int i, int j)
    {
        if (j < 0 || j >= matrix.size())
            return INT_MAX;
        if (i >= matrix.size())
            return 0;

        int result;
        result = matrix[i][j] + min({findSum(matrix, i + 1, j - 1),
                                     findSum(matrix, i + 1, j), findSum(matrix, i + 1, j + 1)});
        return result;
    }
};

// Recursive + Memoization
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int minFallingPathSum(vector<vector<int> > &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = INT_MAX;
        vector<vector<int> > memo(m, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            result = min(result, findSum(matrix, 0, i, memo));
        }
        return result;
    }

    int findSum(vector<vector<int> > &matrix, int i, int j, vector<vector<int> > &memo)
    {
        if (j < 0 || j >= matrix.size())
            return INT_MAX;
        if (i >= matrix.size())
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];
        int result;
        result = matrix[i][j] + min({findSum(matrix, i + 1, j - 1, memo),
                                     findSum(matrix, i + 1, j, memo), findSum(matrix, i + 1, j + 1, memo)});
        return memo[i][j] = result;
    }
};

// Tabulation - Bottom Up
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int minFallingPathSum(vector<vector<int> > &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = INT_MAX;

        vector<vector<int> > dp(m, vector<int>(n, 0));

        // initialization
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        // solving the subproblems
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int leftCol = j - 1 < 0 ? INT_MAX : matrix[i][j] + dp[i - 1][j - 1];
                int sameCol = matrix[i][j] + dp[i - 1][j];
                int rightCol = j + 1 >= n ? INT_MAX : matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min({leftCol, sameCol, rightCol});
            }
        }

        // find the minimum answer
        for (int i = 0; i < m; i++)
        {
            result = min(result, dp[m - 1][i]);
        }
        return result;
    }
};
