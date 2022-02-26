/*
Implementing Dijkstra Algorithm
https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#
*/

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int> > adj[], int S)
    {
        // create a distance array
        vector<int> dis(V, INT_MAX);
        dis[S] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        //(distance, node)
        pq.push({0, S});

        while (!pq.empty())
        {
            int prevdis = pq.top().first; // distance
            int prev = pq.top().second;   // node

            pq.pop();

            for (auto it : adj[prev])
            {
                // it = [node, wt]
                if (prevdis + it[1] < dis[it[0]])
                {
                    dis[it[0]] = prevdis + it[1];
                    pq.push({dis[it[0]], it[0]});
                }
            }
        }
        return dis;
    }
};
