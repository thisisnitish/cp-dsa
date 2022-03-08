/*
Leetcode Question 886. Possible Bipartition
https://leetcode.com/problems/possible-bipartition/
*/

/*
The idea is, we can solve it using graph coloring and check whether all the nodes are
colored with alternate color. If yes, then surely this graph can be grouped into 2
sets and can be bipartite else this graph can't be bipartite.
*/
class Solution
{
public:
    // Time: O(V+E), Space: O(V+E)
    bool possibleBipartition(int n, vector<vector<int> > &dislikes)
    {
        vector<int> color(n + 1, -1);
        vector<int> graph[n + 1];

        // building the graph
        for (auto edge : dislikes)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
                if (!dfs(graph, i, color))
                    return false;
        }
        return true;
    }

    bool dfs(vector<int> graph[], int vertex, vector<int> &color)
    {
        if (color[vertex] == -1)
            color[vertex] = 1;

        for (auto it : graph[vertex])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[vertex];
                if (!dfs(graph, it, color))
                    return false;
            }
            /*
            if the vertex and it of same color then surely the graph can't be
            bipartite
            */
            else if (color[it] == color[vertex])
                return false;
        }
        return true;
    }
};
