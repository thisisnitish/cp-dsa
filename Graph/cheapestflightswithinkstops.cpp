/*
Leetcode Question 787. Cheapest Flights Within K Stops
https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/

// This will give TLE
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int> > &flights, int src, int dst, int K)
    {
        vector<pair<int, int> > adj[n];

        for (vector<int> &flight : flights)
        {
            // u => (v, w)
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        pq.push({0, src, K + 1}); //(price, node, edges)

        while (!pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();

            int price = top[0];
            int node = top[1];
            int edges = top[2]; // no of edges we have from node 'u' to destination

            // if we reach the destination then return the price
            if (node == dst)
                return price;
            if (edges > 0)
            {
                for (auto it : adj[node])
                {
                    int nextNode = it.first;
                    int cost = it.second;
                    pq.push({price + cost, nextNode, edges - 1});
                }
            }
        }
        return -1;
    }
};

// This will passed the test cases
class Solution
{
public:
    // Time: O(NlogN)
    int findCheapestPrice(int n, vector<vector<int> > &flights, int src, int dst, int K)
    {
        vector<pair<int, int> > adj[n];

        for (vector<int> &flight : flights)
        {
            // u => (v, w)
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX); // to avoid TLE
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        pq.push({0, src, 0}); //(price, node, edges)

        while (!pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();

            int price = top[0];
            int node = top[1];
            int edges = top[2];

            // if we reach the destination then return the price
            if (node == dst)
                return price;

            if (edges > K)
                continue;

            // optimization
            if (dist[node] < edges)
                continue;
            dist[node] = edges;

            for (auto it : adj[node])
            {
                int nextNode = it.first;
                int cost = it.second;
                // increase the edge by 1 in order to reach the next step
                pq.push({price + cost, nextNode, edges + 1});
            }
        }
        return -1;
    }
};