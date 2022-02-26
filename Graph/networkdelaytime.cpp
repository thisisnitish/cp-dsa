/*
Leetcode Question 743. Network Delay Time
https://leetcode.com/problems/network-delay-time/
*/

/*
This is an implementation of dijkstra's algorithm
*/
class Solution
{
public:
    // Time: O(n + Elogn), Space: O(n) + O(n)
    int networkDelayTime(vector<vector<int> > &times, int n, int k)
    {
        vector<pair<int, int> > adj[n + 1]; // adjacency list

        // build the directed graph
        for (auto edge : times)
        {
            adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0; // since k is a source node

        //(distance, node)
        pq.push({0, k});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto neighbour : adj[u])
            {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            if (distance[i] == INT_MAX)
                return -1;
            result = max(result, distance[i]);
        }
        return result;
    }
};