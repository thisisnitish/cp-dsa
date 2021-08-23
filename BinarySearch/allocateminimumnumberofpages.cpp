/*
Allocate minimum number of pages
https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
*/

class Solution
{
public:
    //Time: O(NlogN), Space: O(1)
    bool isValid(int A[], int N, int M, int mid)
    {
        int students = 1;
        int pages = 0;
        for (int i = 0; i < N; i++)
        {
            pages += A[i];
            if (pages > mid)
            {
                students++;
                pages = A[i];
            }
            if (students > M)
                return false;
        }
        return true;
    }

    int findPages(int A[], int N, int M)
    {
        if (N < M)
            return -1;
        int low = INT_MIN, high = 0;

        for (int i = 0; i < N; i++)
        {
            low = max(low, A[i]);
            high += A[i];
        }

        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isValid(A, N, M, mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
};