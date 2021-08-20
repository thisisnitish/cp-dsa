/*
Interviewbit Question Search in Bitonic Array!
https://www.interviewbit.com/problems/search-in-bitonic-array/
*/

//Time: O(logN + logN), Space: O(1)
int findPeak(vector<int> &A)
{
    int n = A.size();
    if (n == 1)
        return 0;

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        //Search the peak element in the array except first and last element
        if (mid > 0 && mid < n - 1)
        {
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
                return mid;
            else if (A[mid - 1] > A[mid])
                high = mid - 1;
            else if (A[mid + 1] > A[mid])
                low = mid + 1;
        }
        //case handling for first element
        else if (mid == 0)
        {
            if (A[0] > A[1])
                return 0;
            else
                return 1;
        }
        //case handling for last element
        else if (mid == n - 1)
        {
            if (A[n - 1] > A[n - 2])
                return n - 1;
            else
                return n - 2;
        }
    }
    return -1;
}

int findElement(vector<int> &A, int B, int low, int high, bool asc)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (B == A[mid])
            return mid;
        //Binary Search for Ascending order array
        else if (asc == true)
        {
            if (B > A[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        //Binary Search for Descending order array
        else if (asc == false)
        {
            if (B > A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B)
{
    //Steps
    //1. Find the peak element in the array
    //2. Decide the boundary and then use B.S. according to that
    int index = findPeak(A);
    int found1 = findElement(A, B, 0, index - 1, true);
    int found2 = findElement(A, B, index, A.size() - 1, false);
    if (found1 == -1)
        return found2;
    else if (found2 == -1)
        return found1;
    else
        return -1;
}
