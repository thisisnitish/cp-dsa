/*
Minimum Spanning Tree
https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/#
*/

// Brute Force
class Solution
{
public:
    //Time: O(V^2), Space: O(V) + O(V) + O(V)
    int spanningTree(int V, vector<vector<int> > adj[])
    {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> mstSet(V, false);

        // initially start from first node
        key[0] = 0;
        parent[0] = -1; // no parent for the first node

        for (int i = 0; i < V - 1; i++)
        {
            // get the minimum from the key array but that shouldn't be included
            int mini = INT_MAX, u;
            for (int v = 0; v < V; v++)
            {
                if (mstSet[v] == false && key[v] < mini)
                {
                    mini = key[v];
                    u = v;
                }
            }
            // after getting the minimum include it in the MST
            mstSet[u] = true;
            // after getting the node move towards it's adjacent
            for (auto it : adj[u])
            {
                int node = it[0];
                int wt = it[1];

                if (mstSet[node] == false && wt < key[node])
                {
                    parent[node] = u;
                    key[node] = wt;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < key.size(); i++)
        {
            res += key[i];
        }
        return res;
    }
};

// Optimised approach
class Solution
{
public:
    // Time: O(ElogV)
    int spanningTree(int V, vector<vector<int> > adj[])
    {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> mstSet(V, false);

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        // initially start from first node
        key[0] = 0;
        parent[0] = -1; // no parent for the first node

        //(key[i], i)
        pq.push({key[0], 0});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            // after getting the minimum include it in the MST
            mstSet[u] = true;
            // after getting the node move towards it's adjacent
            for (auto it : adj[u])
            {
                int node = it[0];
                int wt = it[1];

                if (mstSet[node] == false && wt < key[node])
                {
                    parent[node] = u;
                    key[node] = wt;
                    pq.push({key[node], node});
                }
            }
        }

        int res = 0;
        for (int i = 0; i < key.size(); i++)
        {
            res += key[i];
        }
        return res;
    }
};
