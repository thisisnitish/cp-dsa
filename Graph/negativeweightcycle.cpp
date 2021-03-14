/*
Negative weight cycle
https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#
*/

class Solution
{
public:
    /*the basic idea is to implement the bellman ford algorithm. Time: O(V*E)*/
    int isNegativeWeightCycle(int n, vector<vector<int> > edges)
    {
        // Code here
        int sourceNode = 0;
        vector<int> distance(n, INT_MAX);
        distance[sourceNode] = 0;
        int e = edges.size();

        //the relaxation step
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j < e; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];

                if (distance[u] != INT_MAX && distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        //finding the negative cycle
        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            if (distance[u] != INT_MAX && distance[v] > distance[u] + weight)
            {
                return 1;
            }
        }
        return 0;
    }
};