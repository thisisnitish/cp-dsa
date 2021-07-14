/*
Leetcode Question 994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/
*/

/*
It's a pretty standard, simple BFS. We count total number of fresh oranges and push all 
rotten oranges to queue.
Then for every rotten orange at this level, we run a loop numer of items in this level times, 
have a counter if this level turned any fresh orange to rotten. The process continues until 
queue is empty. We subtract every time we turn a fresh to rotten, and push the new rotten 
orange and in the end if we still have fresh oranges left, we couldn't infect(or reach) them 
all, otherwise we did!
Using visited as predecessor for finding the path is a good idea though, except we don't need 
that in this question.
*/
class Solution
{
public:
    //Time: O(m*n), Space: O(n)
    int orangesRotting(vector<vector<int> > &grid)
    {
        if (grid.empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int> > q;

        int freshOranges = 0;
        int minutes = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (freshOranges != 0 && !q.empty())
        {
            int s = q.size();

            for (int i = 0; i < s; i++)
            {
                auto curr = q.front();
                q.pop();

                for (auto dir : dirs)
                {
                    int newR = curr.first + dir.first;
                    int newC = curr.second + dir.second;

                    if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1)
                    {
                        grid[newR][newC] = 2;
                        freshOranges--;
                        q.push({newR, newC});
                    }
                }
            }
            minutes++;
        }
        return freshOranges == 0 ? minutes : -1;
    }
};

/*
//Todo: This solution doesn't work still need to think about this
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = -1;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
                else if(grid[i][j] == 0){
                    dist[i][j] = 0;
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(auto dir : dirs){
                int newR = curr.first + dir.first;
                int newC = curr.second + dir.second;
                
                if(newR >= 0 && newR < m && newC >= 0 && newC < n && dist[newR][newC] == -1){
                    dist[newR][newC] = dist[curr.first][curr.second] + 1;
                    minutes = dist[newR][newC];
                    q.push({newR, newC});
                }
            }
        }
        return minutes;
    }
};
*/
