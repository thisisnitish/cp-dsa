/*
Count Inversions
https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
*/

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    /*the basic idea is to use the merge sort algorithm
    Time: O(NlogN), Space: O(N)*/
    long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right)
    {
        long long int inv_count = 0;
        long long i, j, k;

        i = left, j = mid, k = left;
        while ((i <= mid - 1) && (j <= right))
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inv_count += (mid - i);
            }
        }

        while (i <= mid - 1)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i];

        return inv_count;
    }

    long long int mergeSort(long long arr[], long long temp[], long long left, long long right)
    {
        long long int mid, inv_count = 0;
        if (left < right)
        {
            mid = left + (right - left) / 2;

            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);
            inv_count += merge(arr, temp, left, mid + 1, right);
        }
        return inv_count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }
};