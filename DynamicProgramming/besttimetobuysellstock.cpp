/*
Leetcode Question 121. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

/*
we have given the prices of a stock at each day, Now we have to decide when we will buy and
when we will sell the stock inorder to maximize the profit. The process is very simple...
1. Buy the stock only the day when you see minimum price then the previous day.
2. When the price is more than the price on previous day then sell the stock and find the
maximum profit.
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int buyStockPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            //first buy the stock
            if (prices[i] < buyStockPrice)
                buyStockPrice = prices[i];
            //sell the stock with maximum profit
            else if (prices[i] - buyStockPrice > maxProfit)
                maxProfit = prices[i] - buyStockPrice;
        }
        return maxProfit;
    }
};
