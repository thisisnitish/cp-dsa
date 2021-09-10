/*
D - Knapsack 1
*/

//Todo: Recursive + Memoization


//Bottom Up
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, W;
    cin >> N >> W;

    vector<long long> values(N);
    vector<long long> weight(N);

    for (int i = 0; i < N; i++)
        cin >> weight[i] >> values[i];

    vector<vector<long long> > dp(N + 1, vector<long long>(W + 1));

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (weight[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][W] << endl;
    return (0);
}