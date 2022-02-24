/*
Topological sort
https://practice.geeksforgeeks.org/problems/topological-sort/1/#
*/

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    void toposort(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1; // mark it visited
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                toposort(it, adj, vis, st);
            }
        }
        //when the dfs for 'node' is completed, push it to the stack
        st.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;

        // graph might be disconnected
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // toposort always works for DAG
                toposort(i, adj, vis, st);
            }
        }

        // return the topo sort elements
        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};