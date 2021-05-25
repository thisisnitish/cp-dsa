/*
Fractional Knapsack
https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
Article: https://www.geeksforgeeks.org/fractional-knapsack-problem/
*/

class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    //Time: O(NlogN), Space: O(1)
    static bool comp(struct Item a, struct Item b)
    {
        //calculating the value/weight and sort according to that in
        //decreasing order
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;

        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        double finalValue = 0.0;
        // int currWeight = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= W)
            {
                finalValue += arr[i].value;
                W -= arr[i].weight;
                continue;
            }
            else
            {
                //calculating the value/weight ratio so that we can put the
                //fraction of that weight in the bag
                double r = (double)arr[i].value / (double)arr[i].weight;
                finalValue += W * r;
                break;
            }
        }
        return finalValue;
    }
};
