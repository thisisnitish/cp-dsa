/*
BFS of graph
https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/
*/

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int u, vector<int> adj[], vector<int> &result, vector<bool> &vis)
    {
        queue<int> q;
        q.push(u);
        vis[u] = 1;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            result.push_back(v);

            for (auto it : adj[v])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> result;

        bfs(0, adj, result, vis);
        // for(int i=0; i<V; i++){
        //     if(vis[i] == false)
        //         bfs(i, adj, result, vis);
        // }
        return result;
    }
};
