/*
Leetcode Question 1162. As Far from Land as Possible
https://leetcode.com/problems/as-far-from-land-as-possible/
*/

/*
We will be using BFS for this. Initially distance for each 1 the distance is 0 but for each 0
the distance is -1. Pop the cell from queue, and examine its neighbours and update the 
distance value for that specific cell.
*/
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int maxDistance(vector<vector<int> > &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int maxDistance = -1;

        //dist matrix to calculate the dist for each cell
        //you can put INT_MAX also in place of -1
        vector<vector<int> > dist(m, vector<int>(n, -1));
        queue<pair<int, int> > q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j}); //push the cells which has 1
                }
            }
        }

        //directions
        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (auto dir : dirs)
            {
                int newR = curr.first + dir.first;
                int newC = curr.second + dir.second;

                //check for the valid index
                if (newR >= 0 && newR < m && newC >= 0 && newC < n && dist[newR][newC] == -1)
                {
                    dist[newR][newC] = dist[curr.first][curr.second] + 1;

                    //calculate the max distance other we have to calculate it separately
                    maxDistance = max(maxDistance, dist[newR][newC]);
                    q.push({newR, newC});
                }
            }
        }
        return maxDistance;
    }
};
