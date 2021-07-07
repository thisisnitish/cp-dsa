/*
Leetcode Question 547. Number of Provinces
https://leetcode.com/problems/number-of-provinces/
*/

/*
The main idea of this question is to find the number of connected components in a graph.
I mean, return the total number of provinces. To do this, we will be using dfs to find the
number of connected components in an undirected graph.
*/
class Solution
{
public:
    //Time: O(V+E), Space: O(V)
    int findCircleNum(vector<vector<int> > &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, i);
                count++;
            }
        }

        //total number of provinces
        return count;
    }

    void dfs(vector<vector<int> > &isConnected, vector<bool> &visited, int v)
    {
        visited[v] = true;

        for (int u = 0; u < isConnected.size(); u++)
            if (isConnected[v][u] == 1 && visited[u] == false)
                dfs(isConnected, visited, u);
    }
};
