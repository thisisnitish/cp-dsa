/*
Longest Sub-Array with Sum K 
https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1#
*/

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        int i = 0, j = 0, sum = 0, ans = 0;

        while (j < N)
        {
            sum += A[j];
            //here we have to all the 3 cases because it is a variable size S.W.
            if (sum < K)
                j++;
            else if (sum == K)
            {
                //if we found that sum == k then calulate the length of the
                //window and update it
                ans = max(ans, (j - i) + 1);
                j++;
            }
            else if (sum > K)
            {
                while (sum > K)
                {
                    sum = sum - A[i];
                    i++;

                    if (sum == K)
                    {
                        ans = max(ans, (j - i) + 1);
                    }
                }
                j++;
            }
        }
        return ans;
    }
};
