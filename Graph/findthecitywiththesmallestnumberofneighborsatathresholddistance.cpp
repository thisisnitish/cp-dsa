/*
Leetcode Question 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
*/

/*
This is the 3 step problem
For each city calculate the number of reachable cities within the threshold, then search for 
the optimal city.
Basically, we can do this via dijkstra's Algorithm for every node and at the end sort the 
result, and take the city with the greater value
*/
class Solution
{
public:
    //Time: O(n*elogn + nlogn), Space: O(n)
    //<numberOfCity, city>
    vector<pair<int, int> > result;
    int findTheCity(int n, vector<vector<int> > &edges, int distanceThreshold)
    {
        vector<pair<int, int> > adj[n];

        //step 1
        for (auto edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        //step2
        for (int i = 0; i < n; i++)
            dijkstraAlgorithm(i, n, distanceThreshold, adj);

        //step3
        sort(result.begin(), result.end(), compare);
        return result[0].second;
    }

    void dijkstraAlgorithm(int src, int n, int distanceThreshold, vector<pair<int, int> > adj[])
    {
        //<distance, node>
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        vector<int> distance(n, INT_MAX);

        distance[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int u = pq.top().second;
            // int x = pq.top().first;
            pq.pop();

            for (auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;

                if (distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;

                    pq.push({distance[v], v});
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != src && distance[i] <= distanceThreshold)
                count++;
        }

        result.push_back({count, src});
    }

    bool static compare(const pair<int, int> p1, const pair<int, int> p2)
    {
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second > p2.second;
    }
};
