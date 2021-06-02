/*
k largest elements
https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1#
*/

class Solution
{
public:
    //Time: O(nlogk).Space: O(k)
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int> > minHeap;
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        while (minHeap.size() > 0)
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};