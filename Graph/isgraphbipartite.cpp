/*
Leetcode Question 785. Is Graph Bipartite?
https://leetcode.com/problems/is-graph-bipartite/
*/

//Using BFS
class Solution
{
public:
    /*the basic idea is to use graph coloring problem, since we know the 
    definition of bipartite graph and graph coloring using 2 colors divides 
    the vertices into 2 sets which can tells us whether the graph is a bipartite
    graph or not. Here we are using bfs but we can also use dfs Time: O(V+E)*/
    bool isBipartite(vector<vector<int> > &graph)
    {
        int n = graph.size();

        //-1 means no vertices are colored
        vector<int> color(n, -1);

        /*this loop is for all vertices because it is given that graph might 
        be disconnected, so we have to check for every vertices*/
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                if (!graphColoring(graph, i, color))
                    return false;
        }
        return true;
    }

    bool graphColoring(vector<vector<int> > &graph, int vertex, vector<int> &color)
    {
        color[vertex] = 1;

        queue<int> q;

        //after coloring the vertex push into the queue
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
                    //color with an alternate color and then push it to the queue
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                /*once again we are checking that if u and v are of same 
                color return false*/
                else if (color[v] == color[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//Using DFS
class Solution
{
public:
    //Time: O(V+E), Space: O(V)
    bool isBipartite(vector<vector<int> > &graph)
    {
        int n = graph.size();

        //-1 means no vertices are colored
        vector<int> color(n, -1);

        /*this loop is for all vertices because it is given that graph might 
        be disconnected, so we have to check for every vertices*/
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                if (!graphColoring(graph, i, color))
                    return false;
        }
        return true;
    }

    bool graphColoring(vector<vector<int> > &graph, int vertex, vector<int> &color)
    {
        //if the vertex is not colored color it
        if (color[vertex] == -1)
            color[vertex] = 1;

        //now, color it's adjacent vertices
        for (auto it : graph[vertex])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[vertex];
                if (!graphColoring(graph, it, color))
                    return false;
            }
            else if (color[it] == color[vertex])
                return false;
        }
        return true;
    }
};