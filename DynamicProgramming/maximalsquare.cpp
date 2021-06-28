/*
Leetcode Question 221. Maximal Square
https://leetcode.com/problems/maximal-square/
*/

/*
The basic idea is to go to each cell and try to create a square from that position always 
remember the helper function is going to return the side of the square but why we have used
minimum, it's because all the 3 function calls can go as long as till 1's but better to take
minimum to form a sqaure

Example:
1 1 1 0 1
1 1 0 0 0
0 0 1 0 0
0 0 0 1 0

1 1 1
1 1
    1
      1
      
To form square you need minimum length
*/
//Recursive
class Solution
{
public:
    //Time: O(m*n*3^min(m,n)), Space: O(n)
    int maximalSquare(vector<vector<char> > &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxArea = max(maxArea, helper(matrix, i, j, m, n));
            }
        }
        return maxArea * maxArea;
    }

    int helper(vector<vector<char> > &matrix, int i, int j, int m, int n)
    {

        //base condition
        if (i >= m || j >= n || matrix[i][j] == '0')
            return 0;

        //for creating the square
        return 1 + min({helper(matrix, i + 1, j, m, n), helper(matrix, i, j + 1, m, n), helper(matrix, i + 1, j + 1, m, n)});
    }
};

//Recursive + Memoization
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int maximalSquare(vector<vector<char> > &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int> > memo(m, vector<int>(n, -1));

        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxArea = max(maxArea, helper(matrix, memo, i, j, m, n));
            }
        }
        return maxArea * maxArea;
    }

    int helper(vector<vector<char> > &matrix, vector<vector<int> > &memo, int i, int j, int m, int n)
    {
        if (i >= m || j >= n || matrix[i][j] == '0')
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        memo[i][j] = 1 + min({helper(matrix, memo, i + 1, j, m, n), helper(matrix, memo, i, j + 1, m, n), helper(matrix, memo, i + 1, j + 1, m, n)});

        return memo[i][j];
    }
};
