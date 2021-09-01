/*
Leetcode Question 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
*/

class Solution
{
public:
    //Time: O(N), Space: O(N)
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int i = 0, j = 0, sum = 0, count = 0;

        while (j < arr.size())
        {
            //calculation I
            sum += arr[j];
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                //calculation II
                //find the answer and slide the window
                if (sum / k >= threshold)
                {
                    count++;
                }
                sum = sum - arr[i];
                i++;
                j++;
            }
        }
        return count;
    }
};
