/*
Leetcode Question 684. Redundant Connection
https://leetcode.com/problems/redundant-connection/
*/

/*
If you will reframe this question you will find that this question is all about detecting the
cycle. Basically, we will construct a graph by adding edges one after the other. After each 
addition of new edge we will do dfs traversal to check if any cycle is formed or not. If 
there is a cycle then we know that the last edge addition to the graph led to the cycle 
formation so, we will return that edge.
*/

class Solution
{
public:
    //Time: O(n^2), Space: O(n)
    vector<int> findRedundantConnection(vector<vector<int> > &edges)
    {
        int n = edges.size();
        vector<vector<int> > graph(n + 1);
        vector<bool> visited(n + 1);

        //construct the graph
        for (auto edge : edges)
        {
            fill(visited.begin(), visited.end(), false);
            graph[edge[0]].push_back(edge[1]), graph[edge[1]].push_back(edge[0]);
            //detect the cycle using dfs
            if (dfs(graph, visited, edge[0], -1))
                return edge;
        }
        return {};
    }

    bool dfs(vector<vector<int> > &graph, vector<bool> &visited, int node, int parent)
    {
        if (visited[node])
            return true; //already visited means cycle exists
        visited[node] = true;

        for (auto adjacent : graph[node])
        {
            if (adjacent != parent && dfs(graph, visited, adjacent, node))
                return true;
        }
        return false; //no cycle found
    }
};
