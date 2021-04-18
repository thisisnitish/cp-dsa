/*
Leetcode Question 1049. Last Stone Weight II
https://leetcode.com/problems/last-stone-weight-ii/
*/

class Solution
{
public:
    /*the basic idea is that this question belongs to the classic 0/1 knapsack
    problem. And if you go deeper you will found that it is same as the question:
    minimum subset sum difference. So, better do that problem before doing this
    Time: O(n*sum), Space: O(n*sum)*/
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++)
            sum += stones[i];

        vector<int> v = subsetSum(stones, sum, stones.size());
        int mn = INT_MAX;
        for (int i = 0; i < v.size(); i++)
        {
            mn = min(mn, abs(sum - 2 * v[i]));
        }
        return mn;
    }

    vector<int> subsetSum(vector<int> &stones, int sum, int n)
    {
        vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (stones[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - stones[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        vector<int> temp;
        for (int i = 0; i <= sum / 2; i++)
        {
            if (dp[n][i])
                temp.push_back(i);
        }
        return temp;
    }
};