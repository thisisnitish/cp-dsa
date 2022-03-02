/*
Leetcode Question 684. Redundant Connection
https://leetcode.com/problems/redundant-connection/
*/

/*
This question might sound like detecting the cycle and return the edge. Well this is
a correct approach but the question is how do you find an edge as per the question is
asking.

So, to tackle this, we can reverse our thinking approach. Construct the graph
edge by edge and at the same time detect the cycle by running dfs for every edge.

Inshort, Run DFS when you add a new edge in a graph to find whether that edge causes
a cycle or not in a graph.
*/

class Solution
{
public:
    // Time: O(N^2), Space: O(N)
    vector<int> findRedundantConnection(vector<vector<int> > &edges)
    {
        int n = edges.size();
        vector<int> adj[n + 1];
        vector<bool> visited(n + 1);

        // construct the graph
        for (auto edge : edges)
        {
            fill(visited.begin(), visited.end(), false);
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

            // detect the cycle using dfs, everytime a new edge is added
            if (dfs(adj, visited, edge[0], -1))
                return edge;
        }
        return {};
    }

    bool dfs(vector<int> adj[], vector<bool> &visited, int node, int parent)
    {
        visited[node] = true;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfs(adj, visited, it, node))
                    return true;
            }
            else if (it != parent)
                return true;
        }
        return false;
    }
};
