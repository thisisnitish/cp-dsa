/*
Leetcode Question 1319. Number of Operations to Make Network Connected
https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

class Solution
{
public:
    /*Time: O(V+E)*/
    int makeConnected(int n, vector<vector<int> > &connections)
    {
        if (n > connections.size() + 1)
            return -1;

        vector<bool> visited(n, false);
        vector<vector<int> > adj(n);
        //Make the adjacency list and count the edges
        int edges = 0;
        for (auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
            edges++;
        }

        //Start the DFS and find the number of components
        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                components++;
                DFS(adj, i, visited);
            }
        }

        //if edges is less than the n-1 return -1 not possible
        if (edges < n - 1)
            return -1;

        //count the number of redundant edges
        int redundantEdges = edges - ((n - 1) - (components - 1));
        //check if we can join the components using redundant edges
        if (redundantEdges >= (components - 1))
            return components - 1;
        return -1;
    }

    void DFS(vector<vector<int> > &adj, int v, vector<bool> &visited)
    {
        visited[v] = true;
        for (auto j : adj[v])
        {
            if (!visited[j])
                DFS(adj, j, visited);
        }
    }
};
