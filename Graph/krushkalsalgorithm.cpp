/*CPP code for Krushkal's Algorithms*/

#include <bits/stdc++.h>
using namespace std;
struct Pair
{
    int u;
    int v;
    int wt;
    Pair(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(Pair a, Pair b)
{
    return a.wt < b.wt;
}

int findPar(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    return parent[node] = findPar(parent[node], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int N, m;
    cin >> N >> m;
    vector<Pair> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Pair(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0; i < N; i++)
        parent[i] = i;
    vector<int> rank(N, 0);

    int cost = 0;
    vector<pair<int, int> > mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;
    return 0;
}
