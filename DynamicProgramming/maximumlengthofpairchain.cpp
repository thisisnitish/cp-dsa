/*
Leetcode Question 646. Maximum Length of Pair Chain
https://leetcode.com/problems/maximum-length-of-pair-chain/
*/

//Another problem similar to LIS
class Solution
{
public:
    //Time: O(NlogN + N^2), Space: O(N)
    int findLongestChain(vector<vector<int> > &pairs)
    {
        int n = pairs.size();
        vector<int> dp(n, 1);
        int result = 1;
        sort(pairs.begin(), pairs.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};
