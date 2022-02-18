/*
Leetcode Question 120. Triangle
https://leetcode.com/problems/triangle/
*/

/*
This question is a variation of minimum falling path sum. We can do with recursive and
memoization also. But, I've done with tabulation.
*/
// Solution 1
class Solution
{
public:
    // Time: O(m*n), Space: O(m*n)
    int minimumTotal(vector<vector<int> > &triangle)
    {

        if (triangle.size() == 1)
            return triangle[0][0];
        int m = triangle.size();
        int n = triangle[m - 1].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));

        // dp[i][j] defines min cost to reach cell (i,j)

        // intializing first row
        dp[0][0] = triangle[0][0];

        // solving the subproblems
        for (int i = 1; i < m; i++)
        {
            int s = triangle[i].size();
            for (int j = 0; j < s; j++)
            {
                if (j == 0)
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                else if (j == i)
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }

        int minSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minSum = min(minSum, dp[m - 1][i]);
        }

        return minSum;
    }
};

// Solution 2
class Solution
{
public:
    // Time: O(m*n), Space: O(1)
    int minimumTotal(vector<vector<int> > &triangle)
    {

        if (triangle.size() == 1)
            return triangle[0][0];
        int m = triangle.size();
        int n = triangle[m - 1].size();

        /*
        we will modify the traingle array itself. Let's say
        triangle[i][j] defines min cost to reach cell (i,j)
        */

        // solving the subproblems
        for (int i = 1; i < m; i++)
        {
            int s = triangle[i].size();
            for (int j = 0; j < s; j++)
            {
                if (j == 0)
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
                else if (j == i)
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
                else
                    triangle[i][j] = triangle[i][j] +
                                     min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }

        int minSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minSum = min(minSum, triangle[m - 1][i]);
        }

        return minSum;
    }
};
