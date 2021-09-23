/*
Leetcode Question 122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

/*
The question says we can have an infinite transaction and also we can buy one stock at a 
time and sell at a time. Scenario could be :- Buy, Sell, Buy, Sell. No overlap transactions.
We are checking the if the current value is more than the previous value or not, i.e. if the
stock price goes up then move the selling date but if the stock price goes down then just 
before moving there calculate the profit and move.
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int maxProfit(vector<int> &prices)
    {
        int buyDate = 0, sellDate = 0, maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            //if stock price goes up
            if (prices[i] > prices[i - 1])
            {
                sellDate++;
            }
            else
            {
                //but if it goes down, calculate the profit and then move to that date
                maxProfit += prices[sellDate] - prices[buyDate];
                sellDate = buyDate = i;
            }
        }
        maxProfit += prices[sellDate] - prices[buyDate];
        return maxProfit;
    }
};
