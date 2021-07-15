/*
Leetcode Question 1091. Shortest Path in Binary Matrix
https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/

/*
This is similar to 01 matrix, if you have done it then it will be easy for you. The simple
idea is to use BFS from every cell in all the 8 direction and count the path steps.
*/
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int shortestPathBinaryMatrix(vector<vector<int> > &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0)
            return -1;
        if (n == 0)
            return -1;

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return -1;

        // vector<vector<int>> path(m,vector<int> (n,INT_MAX));
        queue<pair<int, int> > q;

        //for all the directions
        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        //push the first cell and start bfs from here
        grid[0][0] = 1;
        q.push({0, 0});
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            // if we reach the bottom right cell then return the path length
            if (curr.first == m - 1 && curr.second == n - 1)
                return grid[curr.first][curr.second];

            for (auto dir : dirs)
            {
                int newR = curr.first + dir.first;
                int newC = curr.second + dir.second;

                //check for the valid index
                if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 0)
                {
                    grid[newR][newC] = grid[curr.first][curr.second] + 1;
                    q.push({newR, newC});
                }
            }
        }
        return -1;
    }
};
