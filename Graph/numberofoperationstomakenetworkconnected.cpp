/*
Leetcode Question 1319. Number of Operations to Make Network Connected
https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

/*
The basic idea is to find the number of connected components, if we want to connect all
computer so number of connected component must be 1.. number of conneted component -1 will be 
required cabel to make one connection
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

        //make the adjacency list
        for (auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        //Start the DFS and find the number of components
        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS(adj, i, visited);
                components++;
            }
        }
        return components - 1;
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
