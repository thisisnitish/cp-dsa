/*
Leetcode Question 123. Best Time to Buy and Sell Stock III
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

class Solution
{
public:
    //Time: O(N), Space: O(N)
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int maxProfitIfSoldToday = 0;
        int leastSoFar = prices[0];
        vector<int> maxProfitIfSoldUptoToday(n);

        for (int i = 1; i < n; i++)
        {
            leastSoFar = min(leastSoFar, prices[i]);
            maxProfitIfSoldToday = prices[i] - leastSoFar;

            if (maxProfitIfSoldToday > maxProfitIfSoldUptoToday[i - 1])
                maxProfitIfSoldUptoToday[i] = maxProfitIfSoldToday;
            else
                maxProfitIfSoldUptoToday[i] = maxProfitIfSoldUptoToday[i - 1];
        }

        int maxProfitIfBoughtToday = 0;
        int maxAfterToday = prices[n - 1];
        vector<int> maxProftIfBoughtTodayOrAfterToday(n);

        for (int i = n - 2; i >= 0; i--)
        {
            maxAfterToday = max(maxAfterToday, prices[i]);
            maxProfitIfBoughtToday = maxAfterToday - prices[i];

            if (maxProfitIfBoughtToday > maxProftIfBoughtTodayOrAfterToday[i + 1])
                maxProftIfBoughtTodayOrAfterToday[i] = maxProfitIfBoughtToday;
            else
            {
                maxProftIfBoughtTodayOrAfterToday[i] =
                    maxProftIfBoughtTodayOrAfterToday[i + 1];
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = max(maxProfitIfSoldUptoToday[i] +
                             maxProftIfBoughtTodayOrAfterToday[i],
                         result);
        }
        return result;
    }
};
