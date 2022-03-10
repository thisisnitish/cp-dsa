/*
Leetcode Question 1319. Number of Operations to Make Network Connected
https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

/*
As the question says:
You can extract certain cables between two directly connected computers, and place
them between any pair of disconnected computers to make them directly connected.

Let's try to make it simple.

Now, Let say we have 2 computers and there is no edge b/w them. So, we need only 1
edge to connect both the computers, which means, number of times we need to
connect both the computers will be 1.

Let's take an example from first Testcase, (Refer Question)
You see there are 2 disconected components and, computer 1 & computer 3 are connected
in right side via 1 edge only.

Similarly, in the second Testcase, (Refer Question)
We have 3 components in total and we are using 2 edges in total to connect all the 3
components.

In short, the number of components we will have, then number of components-1 edges
will take to connect all the components.

Let's say 1 edge takes 1 unit of time.
Hence, number of components-1 edges will take number of components-1 unit of time.
*/
class Solution
{
public:
    // Time: O(V+E), Space: O(V+E)
    int makeConnected(int n, vector<vector<int> > &connections)
    {
        if (n > connections.size() + 1)
            return -1;

        vector<bool> visited(n, false);
        vector<int> adj[n];

        // build the graph
        for (auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        // Start the DFS and find the number of components
        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, i, visited);
                components++;
            }
        }
        return components - 1;
    }

    void dfs(vector<int> adj[], int v, vector<bool> &visited)
    {
        visited[v] = true;
        for (auto j : adj[v])
        {
            if (!visited[j])
                dfs(adj, j, visited);
        }
    }
};