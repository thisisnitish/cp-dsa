/*
Leetcode Question 743. Network Delay Time
https://leetcode.com/problems/network-delay-time/
*/

class Solution
{
public:
    /*the basic idea is that indirectly the question itself is asking single
    source shortest path, so we can apply dijsktra's algorithm.
    Time: O(ElogV)*/
    int networkDelayTime(vector<vector<int> > &times, int n, int k)
    {
        vector<vector<pair<int, int> > > adj(n + 1);

        for (auto edge : times)
        {
            adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;

        pq.push(make_pair(0, k));

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
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        //since we want the maximum from the distance
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