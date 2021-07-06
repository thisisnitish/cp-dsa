/*
Leetcode Question 210. Course Schedule II
https://leetcode.com/problems/course-schedule-ii/
*/

/*
The question is asking about an order of the nodes, & we know that ordering of the nodes is
maintained by topological sort. So, here we have to apply a topological sort but we have to
take care that the graph shouldn't be cyclic. Here, we are using Kahn's Algorithm which uses
BFS for topological sort.
*/
class Solution
{
public:
    //Time: O(V+E), Space: O(V)
    vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites)
    {

        //create a graph
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites)
        {

            //push first node first and then second node as the question says
            adj[edge[1]].push_back(edge[0]);

            //calculating the degree of the nodes
            indegree[edge[0]]++;
        }

        vector<int> result;

        if (kahnsAlgorithm(adj, indegree, numCourses, result))
            return result;
        return {};
    }

    bool kahnsAlgorithm(vector<int> adj[], vector<int> &indegree, int numCourses, vector<int> &result)
    {

        queue<int> q;

        //push all the nodes to the queue which has indegree 0
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            result.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (count == numCourses)
            return true;
        return false;
    }
};
