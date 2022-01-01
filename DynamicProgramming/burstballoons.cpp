/*
Leetcode Question 312. Burst Balloons
https://leetcode.com/problems/burst-balloons/
*/

class Solution
{
public:
    // Time: O(N^3), Space: O(N^2)
    vector<vector<int> > memo;
    int maxCoinsHelper(vector<int> &nums, int i, int j, int n)
    {
        // base case
        if (i > j)
            return 0;

        // if element already exists
        if (memo[i][j] != -1)
            return memo[i][j];

        // if only one element exists
        if (i == j)
        {
            int temp = nums[i];
            if (i - 1 >= 0)
                temp *= nums[i - 1];
            if (i + 1 < n)
                temp *= nums[i + 1];
            return temp;
        }

        /*
        This is the case where we have to burst the (i, k-1) and (k+1, j) balloons
        first and then kth balloon burst at the end.
        */

        int ans = 0;
        for (int k = i; k <= j; k++)
        {
            int burstleftAndRightBalloons = (maxCoinsHelper(nums, i, k - 1, n) +
                                             maxCoinsHelper(nums, k + 1, j, n));

            int burstkthBalloon = nums[k];
            if (i - 1 >= 0)
                burstkthBalloon *= nums[i - 1];
            if (j + 1 < n)
                burstkthBalloon *= nums[j + 1];

            int temp = burstleftAndRightBalloons + burstkthBalloon;
            ans = max(ans, temp);
        }
        return memo[i][j] = ans;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        memo.resize(n + 1, vector<int>(n + 1, -1));

        vector<int> arr = nums;
        arr.push_back(1);
        arr.insert(arr.begin() + 0, 1);
        int size = n + 2;
        return maxCoinsHelper(arr, 1, n, size);
    }
};
