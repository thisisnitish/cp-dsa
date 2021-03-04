/*
Topological sort
https://practice.geeksforgeeks.org/problems/topological-sort/1#
*/

class Solution{
public:
    /*this is the standard implementation of topological sort, Time: O(V+E)*/
    void topologicalSortUtil(int v, vector<int> &visited, stack<int> &Stack, vector<int> adj[])
    {
        visited[v] = true;

        vector<int>::iterator itr;
        for (itr = adj[v].begin(); itr != adj[v].end(); itr++)
        {
            if (!visited[*itr])
            {
                topologicalSortUtil(*itr, visited, Stack, adj);
            }
        }
        Stack.push(v);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        stack<int> Stack;
        vector<int> visited(V, false);
        vector<int> result;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                topologicalSortUtil(i, visited, Stack, adj);
            }
        }

        while (!Stack.empty())
        {
            result.push_back(Stack.top());
            Stack.pop();
        }
        return result;
    }
}