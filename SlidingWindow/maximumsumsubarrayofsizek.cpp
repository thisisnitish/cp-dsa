/*
Max Sum Subarray of size K 
https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#
*/

class Solution
{
public:
    int maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        int i = 0, j = 0, sum = 0, mx = INT_MIN;

        while (j < N)
        {
            sum += Arr[j];
            if (j - i + 1 < K)
            {
                j++;
            }
            else if (j - i + 1 == K)
            {
                mx = max(mx, sum);
                sum = sum - Arr[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};