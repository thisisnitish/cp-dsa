/*
Leetcode Question 378. Kth Smallest Element in a Sorted Matrix
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

/*
We have to get the kth smallest element in a sorted matrix, that means we need to keep the k small
elements, so that we can easily find kth smallest element. Hence we will be using max heap.
*/
class Solution
{
public:
    //Time: O(N^2*logk), Space: O(k)
    int kthSmallest(vector<vector<int> > &matrix, int k)
    {

        //creating the max heap
        priority_queue<int> maxheap;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                maxheap.push(matrix[i][j]);

                //if the size of the maxheap is more than k just pop the element
                if (maxheap.size() > k)
                    maxheap.pop();
            }
        }
        //kth smallest element will be at top
        return maxheap.top();
    }
};
