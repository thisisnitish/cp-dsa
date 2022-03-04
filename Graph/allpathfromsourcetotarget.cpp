/*
Leetcode Question 797. All Paths From Source to Target
https://leetcode.com/problems/all-paths-from-source-to-target/
*/

class Solution
{
public:
    // Time: O(2^n), Space: O(n)
    vector<vector<int> > result;
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> > &graph)
    {
        int source = 0;
        int size = graph.size() - 1;
        vector<int> path;
        dfs(graph, source, size, path);
        return result;
    }

    void dfs(vector<vector<int> > &graph, int source, int size, vector<int> &path)
    {

        // add the node to the path
        path.push_back(source);

        // base case
        if (source == size)
        {
            result.push_back(path);
            return;
        }

        for (auto v : graph[source])
        {
            dfs(graph, v, size, path);
            /*pop here because you need to start from another
            edge in order to reach target*/
            path.pop_back();
        }
    }
};
