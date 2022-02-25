/*
Leetcode Question 207. Course Schedule
https://leetcode.com/problems/course-schedule/
*/

/*
This question is all about detecting cycle in a graph or not. If cycle exists, then
all the courses will be interdependent and we will not be able finish the courses.
*/
// Solution 1
class Solution
{
public:
    // Time: O(V + E), Space: O(V) + O(V)
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // build the graph
        vector<int> adj[numCourses];
        for (auto pre : prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
            if (vis[i] == 0)
                if (isCyclic(adj, vis, dfsVis, i))
                    return false;

        return true;
    }

    bool isCyclic(vector<int> adj[], vector<int> &vis, vector<int> &dfsVis, int v)
    {

        vis[v] = 1;
        dfsVis[v] = 1;

        for (auto it : adj[v])
        {
            if (!vis[it])
            {
                if (isCyclic(adj, vis, dfsVis, it)) // if cycle exists return true
                    return true;
            }
            else if (dfsVis[it] == 1)
                return true; // if cycle exists return true
        }

        dfsVis[v] = 0;
        return false;
    }
};

/*
We can also use kahn's Alogrithm to detect cycle in a graph. Because, if cycle exists
ordering of the courses will not be possible, so topological sort will also not
possible.
*/
// Solution 2
class Solution
{
public:
    // Time: O(V + E), Space: O(V) + O(V)
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // build the graph
        vector<int> adj[numCourses];
        for (auto pre : prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> indegree(numCourses, 0);

        // calculate the indegrees of all nodes
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        // push all the nodes which have indegrees 0
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        // now start BFS or kahn's algorithm
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (count == numCourses)
            return true; // cycle doesn't exists
        return false;    // cycle exists
    }
};
