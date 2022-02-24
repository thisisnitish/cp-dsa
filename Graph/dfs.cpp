/*
DFS of Graph
https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/
*/

class Solution
{
public:
    void dfs(int v, vector<int> adj[], vector<bool> &vis, vector<int> &storedfs)
    {
        storedfs.push_back(v);
        vis[v] = true; // mark it visited
        // go to the adjacent node and call recursively the adjacent node
        for (auto u : adj[v])
        {
            if (!vis[u])
                dfs(u, adj, vis, storedfs);
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> vis(V + 1, false);
        vector<int> storedfs;
        dfs(0, adj, vis, storedfs);
        //   for(int i=0; i<=V; i++){
        //       if(!vis[i]){
        //           dfs(i, adj, vis, storedfs);
        //       }
        //   }
        return storedfs;
    }
};