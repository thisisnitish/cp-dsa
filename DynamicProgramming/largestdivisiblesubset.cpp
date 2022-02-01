/*
Leetcode Question 368. Largest Divisible Subset
https://leetcode.com/problems/largest-divisible-subset/
*/

/*
This is a 3 step solution. This is a variation of LIS
1. Sort the array
2. Get the LIS till every index.
3. Find the subset
*/

class Solution
{
public:
    // Time: O(NlogN + N^2 + N), Space: O(N + length of subset)
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end()); //Step 1

        vector<int> dp(n, 1);
        int res = 1; // shows the length of the LIS
        for (int i = 0; i < n; i++)     //Step 2
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

        int prevElement = -1;
        vector<int> subset;             //Step 3
        for (int i = n - 1; i >= 0; i--)
        {
            if (res == dp[i] && (prevElement == -1 || prevElement % nums[i] == 0))
            {
                subset.push_back(nums[i]);
                res--;
                prevElement = nums[i];
            }
        }
        return subset;
    }
};
