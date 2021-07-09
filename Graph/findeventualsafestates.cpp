/*
Leetcode Question 802. Find Eventual Safe States
https://leetcode.com/problems/find-eventual-safe-states/
*/

/*
The crux of the problem is whether you can reach a cycle from the node you start in. If you 
can, then there is a way to avoid stopping indefinitely; and if you can't, then after some 
finite number of steps you'll stop.

Thinking about this property more, a node is eventually safe if all it's outgoing edges are 
to nodes that are eventually safe.

This gives us the following idea: we start with nodes that have no outgoing edges - those are 
eventually safe. Now, we can update any nodes which only point to eventually safe nodes - 
those are also eventually safe. Then, we can update again, and so on.

For this we have to reverse the edges of the graph and we will be using kahns algorithm.
*/
class Solution
{
public:
    //Time: O(V+E), Space: O(V)
    vector<int> eventualSafeNodes(vector<vector<int> > &graph)
    {
        int n = graph.size();
        vector<int> indegree(n, 0);

        //calculating the indegree
        for (int i = 0; i < n; i++)
            indegree[i] = graph[i].size();

        vector<vector<int> > rGraph = reverseEdges(graph);

        return kahnsAlgorithm(rGraph, indegree, n);
    }

    vector<vector<int> > reverseEdges(vector<vector<int> > &graph)
    {
        int n = graph.size();

        //reverse the edges
        vector<vector<int> > rGraph(n);
        for (int i = 0; i < n; i++)
        {
            for (auto j : graph[i])
            {
                rGraph[j].push_back(i);
            }
        }
        return rGraph;
    }

    vector<int> kahnsAlgorithm(vector<vector<int> > &rGraph, vector<int> &indegree, int n)
    {
        queue<int> q;

        //push all the elements which has 0 indegree
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : rGraph[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                result.push_back(i);

        return result;
    }
};
