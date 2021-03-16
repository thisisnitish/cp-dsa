/*
Leetcode Question 207. Course Schedule
https://leetcode.com/problems/course-schedule/
*/

class Solution
{
public:
    /*the basic idea of this question is we have to detect cycle in the graph.
    Please read the standard problem of detecting the cycle in a graph and 
    you are good to go in this question. Time: O(V + E), Space: O(V)*/
    bool canFinish(int numCourses, vector<vector<int> > &prerequisites)
    {
        vector<vector<int> > adj(numCourses, vector<int>());
        for (vector<int> &pre : prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
            if (visited[i] == 0 && !isCyclic(adj, visited, i))
                return false;

        return true;
    }

    bool isCyclic(vector<vector<int> > &adj, vector<int> &visited, int v)
    {
        if (visited[v] == 1)
            return false;
        if (visited[v] == 2)
            return true;
        visited[v] = 1;
        for (int ad : adj[v])
        {
            if (!isCyclic(adj, visited, ad))
                return false;
        }

        visited[v] = 2;
        return true;
    }
};