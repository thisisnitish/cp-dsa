/*
Leetcode Question 368. Largest Divisible Subset
https://leetcode.com/problems/largest-divisible-subset/
*/

/*
    Another variation of LIS.
    we can tweak the statement a little bit: Longest increasing subsequence such that every current element is divisible by prev element.
    Now, the question seems very meaningful.
*/
class Solution
{
public:
    //Time: O(NlogN + N^2 + N), Space: O(N)
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                res = max(res, dp[i]);
            }
        }

        int prev = -1;
        vector<int> result;
        for (int i = n - 1; i >= 0; i--)
        {
            if (res == dp[i] && (prev == -1 || prev % nums[i] == 0))
            {
                result.push_back(nums[i]);
                res--;
                prev = nums[i];
            }
        }
        return result;
    }
};
