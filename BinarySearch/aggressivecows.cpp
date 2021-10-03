/*
AGGRCOW - Aggressive cows
https://www.spoj.com/problems/AGGRCOW/
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidDistance(vector<int> &dist, int cows, int distance)
{
    int cow = 1;
    int prevCow = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - prevCow >= distance)
        {
            cow++;
            prevCow = v[i];
        }
        if (cow >= cows)
            return true;
    }
    return false;
}

void solve()
{
    int n, cows;
    cin >> n >> cows;
    vector<int> dist(n);

    for (int i = 0; i < n; i++)
    {
        cin >> dist[i];
    }

    sort(dist.begin(), dist.end());
    int low = dist[0], high = dist[n - 1] - dist[0];
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValidDistance(dist, cows, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
