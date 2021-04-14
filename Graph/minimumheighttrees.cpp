/*
Leetcode Question 310. Minimum Height Trees
https://leetcode.com/problems/minimum-height-trees/
*/

class Solution
{
public:
    /*the basic idea is to do the bfs because the question is and
    find the degree of the vertices and if the deg are 1 that means those
    are leaf node, level by level and keep removing those leaf nodes until 
    you reach the middle of the graph with maximum 2 vertices. There will be 
    maximum 2 such vertices that will form minimum height trees. 
    (middle of the graph) Time: O(n)*/
    vector<int> findMinHeightTrees(int n, vector<vector<int> > &edges)
    {
        if (n == 1)
            return {0};

        //creating the adjacency list
        vector<vector<int> > graph(n);
        vector<int> degree(n, 0);
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);

            //calculating the degrees
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        //it's time for bfs
        queue<int> Q;
        //push degree one nodes(leaf) in the queue
        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                Q.push(i);

        //to keep the MHT nodes
        vector<int> result;
        while (!Q.empty())
        {
            int n = Q.size();

            //clear the MHT nodes
            result.clear();

            //remove leaves level by level
            //newly added leaves will be removed in next turn
            while (n--)
            {
                int node = Q.front();
                Q.pop();

                result.push_back(node);

                //process the neigbours node
                for (int i = 0; i < graph[node].size(); i++)
                {
                    degree[graph[node][i]]--;

                    //push the leaf node in to the queue
                    if (degree[graph[node][i]] == 1)
                        Q.push(graph[node][i]);
                }
            }
        }
        return result;
    }
};