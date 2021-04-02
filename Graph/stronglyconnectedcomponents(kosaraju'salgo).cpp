/*
Strongly Connected Components (Kosaraju's Algo)
https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
*/

class Solution
{
public:
    /*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    /*this is a standard question, it's just an implementation of
    kosaraju's algorithm. Time: O(V+E)*/
    void fillOrder(int v, vector<bool> &visited, stack<int> &Stack, vector<int> adj[])
    {
        visited[v] = true;

        for (auto u : adj[v])
        {
            if (!visited[u])
                fillOrder(u, visited, Stack, adj);
        }
        Stack.push(v);
    }

    // vector<vector<int>> getTranspose(vector<int> adj[], int V){
    //     vector<vector<int>> newGraph;
    //     for(int v=0; v<V; v++){
    //         for(auto x : adj[v])
    //             newGraph[x].push_back(v);
    //     }
    //     return newGraph;
    // }

    void DFSUtil(int v, vector<bool> &visited, vector<int> graphTranspose[])
    {
        visited[v] = true;
        for (auto u : graphTranspose[v])
        {
            if (!visited[u])
                DFSUtil(u, visited, graphTranspose);
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                fillOrder(i, visited, Stack, adj);
        }

        // vector<vector<int>> graphTranspose;
        vector<int> graphTranspose[V];
        for (int v = 0; v < V; v++)
        {
            for (int u : adj[v])
            {
                graphTranspose[u].push_back(v);
            }
        }

        for (int i = 0; i < V; i++)
            visited[i] = false;

        int components = 0;
        while (!Stack.empty())
        {
            int v = Stack.top();
            Stack.pop();

            if (visited[v] == false)
            {
                DFSUtil(v, visited, graphTranspose);
                components++;
            }
        }
        return components;
    }
};
