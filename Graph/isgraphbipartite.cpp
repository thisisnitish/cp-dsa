/*
Leetcode Question 785. Is Graph Bipartite?
https://leetcode.com/problems/is-graph-bipartite/
*/

/*
the basic idea is to use graph coloring problem, since we know the
definition of bipartite graph and graph coloring using 2 colors divides
the vertices into 2 sets which can tells us whether the graph is a bipartite
graph or not. Here we are using bfs but we can also use dfs.
*/

// using BFS
class Solution
{
public:
    // Time: O(N+E), Space: O(N+E) + O(N) + O(N)
    bool isBipartite(vector<vector<int> > &graph)
    {
        int n = graph.size();

        //-1 means no vertices are colored
        vector<int> color(n, -1);

        /*
        this loop is for all vertices because it is given that graph might
        be disconnected, so we have to check for every vertices
        */
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                if (!checkBipartite(graph, i, color))
                    return false;
        }
        return true;
    }

    bool checkBipartite(vector<vector<int> > &graph, int vertex, vector<int> &color)
    {
        queue<int> q;
        color[vertex] = 1; // mark it visited for the first with anything 0 or 1
        // after coloring the vertex push into the queue
        q.push(vertex);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            /*find all adjacent non-colored vertices and color them*/
            for (auto v : graph[u])
            {
                if (color[v] == -1)
                {
                    // color with an alternate color and then push it to the queue
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                /*
                once again we are checking that if u and v are of same
                color return false
                */
                else if (color[v] == color[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// using DFS
class Solution
{
public:
    // Time: O(N+E), Space: O(N+E) + O(N) + O(N)
    bool isBipartite(vector<vector<int> > &graph)
    {
        int n = graph.size();

        //-1 means no vertices are colored
        vector<int> color(n, -1);

        /*
        this loop is for all vertices because it is given that graph might
        be disconnected, so we have to check for every vertices
        */
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                if (!checkBipartite(graph, i, color))
                    return false;
        }
        return true;
    }

    bool checkBipartite(vector<vector<int> > &graph, int vertex, vector<int> &color)
    {
        // if it is for the first time
        if (color[vertex] == -1)
            color[vertex] = 1;

        // color the adjacent nodes
        for (auto it : graph[vertex])
        {
            if (color[it] == -1)
            {
                // color with opposite color to its adjacent node
                color[it] = 1 - color[vertex];
                if (!checkBipartite(graph, it, color))
                    return false;
            }
            // if 'it' and 'vertex' are of same color then graph is not bipartite
            else if (color[it] == color[vertex])
                return false;
        }
        return true;
    }
};
