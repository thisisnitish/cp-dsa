/*
Leetcode Question 542. 01 Matrix
https://leetcode.com/problems/01-matrix/
*/

/*
For our BFS routine, we keep a queue, q to maintain the queue of cells to be examined next.
We start by adding all the cells with 0s to q.
Intially, distance for each 0 cell is 0 and distance for each 1 is INT_MAX, which is updated 
during the BFS.
Pop the cell from queue, and examine its neighbours. If the new calculated distance for 
neighbour {i,j} is smaller, we add {i,j} to q and update dist[i][j].
*/
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    vector<vector<int> > updateMatrix(vector<vector<int> > &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int> > dist(m, vector<int>(n, INT_MAX));

        // using queue to store position of elements whose answer we know, to use it to
        //derive others' distances
        queue<pair<int, int> > q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j}); //put all the cells which contains 0s into queue
                }
            }
        }

        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {

            // position of element whose result is known
            auto curr = q.front();
            q.pop();

            // traversing in all possible direction
            for (auto dir : dirs)
            {

                int newR = curr.first + dir.first;
                int newC = curr.second + dir.second;

                // if the new position is valid
                if (newR >= 0 && newR < m && newC >= 0 && newC < n && mat[newR][newC] == 1 && dist[newR][newC] == INT_MAX)
                {
                    /*
                    update the distance if previous distance is more than distance of current 
                    element + 1 (bcoz. we can move only 1 step at a time)
                    */
                    dist[newR][newC] = dist[curr.first][curr.second] + 1;
                    q.push({newR, newC});

                    /*
                    this is also a correct approach and to use this we need to remove the
                    dist array and mat array from the above if condition comment above 
                    statments
                    if(dist[newR][newC] > dist[curr.first][curr.second] + 1){
                        dist[newR][newC] = dist[curr.first][curr.second] + 1;
                        
                        // adding result to queue to use to derive other distances
                        q.push({newR, newC});
                    }
                    */
                }
            }
        }
        return dist;
    }
};
