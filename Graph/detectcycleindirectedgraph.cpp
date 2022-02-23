/*
Detect cycle in a directed graph
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/#
*/

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    // we are using DFS here
    // Time: O(N+E), Space: O(2N) + Stack Space
    bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
    {
        vis[node] = 1;
        dfsVis[node] = 1;

        // go for the adjacent node
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (checkCycle(it, adj, vis, dfsVis))
                    return true;
            }
            // if both vis[it] and dfsVis[it] equals 1 then cycle exists
            else if (dfsVis[it] == 1)
                return true;
        }
        dfsVis[node] = 0; // when we didn't found a cycle
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> dfsVis(V, 0);

        // graph might be disconnected
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsVis))
                    return true;
            }
        }
        return false;
    }
};
