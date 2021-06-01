/*
Kth smallest element
https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#
*/

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    //Time: O(nlogk), Space: O(k);
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> maxHeap;
        for (int i = l; i <= r; i++)
        {
            maxHeap.push(arr[i]);

            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        return maxHeap.top();
    }
};