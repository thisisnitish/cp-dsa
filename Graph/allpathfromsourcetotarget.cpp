/*
Leetcode Question 797. All Paths From Source to Target
https://leetcode.com/problems/all-paths-from-source-to-target/
*/

class Solution
{
public:
    /*the basic idea is to just implement the dfs with some tweaks.
    Time: O(V+E)*/
    int size;
    vector<vector<int> > result;
    vector<int> path;
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> > &graph)
    {
        int source = 0;
        size = graph.size() - 1;
        dfs(graph, source);
        return result;
    }

    void dfs(vector<vector<int> > &graph, int source)
    {
        path.push_back(source);

        /*if this happens then there is not possible to move further from 
        that path, so we have to start again from beginning for other path*/
        if (source == size)
            result.push_back(path);

        for (auto v : graph[source])
        {
            dfs(graph, v);
            path.pop_back();
        }
    }
};