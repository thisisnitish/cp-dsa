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
    //O(V+E), Space: O(V)
    void dfs(vector<int> adj[], int node, stack<int> &st, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
                dfs(adj, it, st, visited);
        }
        st.push(node);
    }

    void reverseDFS(vector<int> transpose[], int node, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto it : transpose[node])
        {
            if (!visited[it])
                reverseDFS(transpose, it, visited);
        }
    }

    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //Step 1 -> Topological Sort
        //Step 2 -> Transpose of graph
        //Step 3 -> Again DFS of Tranposed graph till the stack becomes empty

        vector<bool> visited(V, false);
        stack<int> st;

        //Step 1
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(adj, i, st, visited);
        }

        //Step 2
        vector<int> transpose[V];
        for (int v = 0; v < V; v++)
        {
            visited[v] = false;
            for (auto u : adj[v])
            {
                transpose[u].push_back(v);
            }
        }

        //Step 3
        int scc = 0;
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (!visited[x])
            {
                reverseDFS(transpose, x, visited);
                scc++;
            }
        }
        return scc;
    }
};
