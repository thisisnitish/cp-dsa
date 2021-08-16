/*
Rotation 
https://practice.geeksforgeeks.org/problems/rotation4723/1#
*/

class Solution
{
public:
    //Time: O(nlogn), Space: O(1)
    int findKRotation(int arr[], int n)
    {
        if (arr[0] < arr[n - 1])
            return 0;
        int low = 0, high = n - 1;
        int result = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
                return mid;
            else if (arr[mid] > arr[high])
                low = mid + 1;
            else if (arr[mid] < arr[high])
                high = mid - 1;
        }
        return result;
        //return INT_MAX;
    }
};