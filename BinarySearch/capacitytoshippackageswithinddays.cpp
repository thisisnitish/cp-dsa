/*
Leetcode Question 1011. Capacity To Ship Packages Within D Days
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

class Solution
{
public:
    //Time: O(NlogN), Space: O(1)
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = 0, high = 0;
        for (auto w : weights)
        {
            low = max(low, w);
            high += w;
        }

        int result = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isValid(weights, days, mid))
            {
                result = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return result;
    }

    bool isValid(vector<int> &weights, int days, int max)
    {
        int day = 1;
        int totalWeights = 0;

        for (auto w : weights)
        {
            totalWeights += w;
            if (totalWeights > max)
            {
                day++;
                totalWeights = w;
            }

            if (day > days)
                return false;
        }
        return true;
    }
};
