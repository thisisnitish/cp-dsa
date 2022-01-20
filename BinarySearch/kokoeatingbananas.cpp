/*
Leetcode Question 875. Koko Eating Bananas
https://leetcode.com/problems/koko-eating-bananas/
*/

class Solution
{
public:
    // Time: O(NlogN)
    bool canEatBananas(vector<int> &piles, int k, int h)
    {
        int hourSpent = 0;

        for (auto pile : piles)
        {

            /*
            this represents, how much you can eat from a pile. Ex - 24 bananas
            in a pile, but k = 4 bananas/hr, then hr spent will be 6 hrs.
            But if k = 25, then you will eat 24 bananas in 6 hrs. but you will eat
            25th bananas in 7th hr. That is the reason we have written a second
            line.
            */
            // hourSpent += pile/k;
            // if(pile % k != 0) hourSpent++;

            //this is a crux of above two lines
            hourSpent += ceil(1.0 * pile / k);
        }
        if (hourSpent <= h)
            return true;
        return false;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1; // minimum banans i can eat is 1

        // maximum banans i can eat is max of all
        int high = *max_element(piles.begin(), piles.end());

        int result = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            /*
            if we get the valid k value, then we need to move to the left
            side because we need minimum value of k
            */

            if (canEatBananas(piles, mid, h))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};
