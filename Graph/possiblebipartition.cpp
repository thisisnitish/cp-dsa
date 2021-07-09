/*
Leetcode Question 886. Possible Bipartition
https://leetcode.com/problems/possible-bipartition/
*/

/*
The crux of this problem is to check whether the graph is bipartite or not, if it is then
return true else false. To check the graph bipartite or not we will be using graph coloring
algorithm which uses dfs.
*/
class Solution
{
public:
    //Time: O(V+E), Space: O(V)
    bool possibleBipartition(int n, vector<vector<int> > &dislikes)
    {
        vector<int> color(n + 1, -1);

        // vector<vector<int>> graph(n+1);
        vector<int> graph[n + 1];

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
            else if (color[it] == color[vertex])
                return false;
        }
        return true;
    }
};
