/*
Leetcode Question 1283. Find the Smallest Divisor Given a Threshold
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
*/

class Solution
{
public:
    //Time: O(NlogN), Space: (N)
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        /*
        low is 1 atleast 1 will be there as a divisor so that it can divide all the element
        and high is maximum ele of nums arr, the reason for this is, if you will check you
        will find that the divisor greater than or equal to the max ele of arr will give
        result at size of the array. So, at the end high value will be the max of the arr 
        ele
        */
        int low = 1, high = 0;
        for (auto n : nums)
            high = max(high, n);

        int result = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isValid(nums, threshold, mid))
            {
                result = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return result;
    }

    bool isValid(vector<int> &nums, int threshold, int divisor)
    {
        int total = 0;
        for (auto n : nums)
        {
            total += (n % divisor) == 0 ? (n / divisor) : (n / divisor) + 1;
        }
        return total <= threshold;
    }
};