/*
Leetcode Question 787. Cheapest Flights Within K Stops
https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/

class Solution
{
public:
    /*the basic idea is to implement the dijkstra's algorithm with some changes.
    here we have to find the shortest path between src to dest with K+1 edges.
    Time: O(E*logV)*/
    int findCheapestPrice(int n, vector<vector<int> > &flights, int src, int dst, int K)
    {
        vector<vector<pair<int, int> > > adj(n);

        //creating the adjacency list
        for (vector<int> &flight : flights)
        {
            //u => v, w
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        //creating the priority queue to store the {distance, node, number of edges}
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        pq.push({0, src, K + 1});

        while (!pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();

            int d = top[0]; //distance
            int u = top[1]; //node
            int e = top[2]; //edges

            //if the dst is same is a u then we have reached the destination
            //then return it
            if (u == dst)
                return d;
            //if not reach the destination then push into the queue and
            //simultaneously decrease e values
            if (e > 0)
            {
                for (pair<int, int> &v : adj[u])
                {
                    pq.push({d + v.second, v.first, e - 1});
                }
            }
        }
        //if we got nothing then return -1
        return -1;
    }
};