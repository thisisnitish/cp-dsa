/*
Leetcode Question 378. Kth Smallest Element in a Sorted Matrix
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

class Solution
{
public:
    /*using maxheap, basic idea is to put the elements in the
    pq and if pq size > k pop the elements and atlast return the 
    top value. Time: O(N^2), Space: O(N)*/
    int kthSmallest(vector<vector<int> > &matrix, int k)
    {
        priority_queue<int> temp;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                temp.push(matrix[i][j]);
                if (temp.size() > k)
                {
                    temp.pop();
                }
            }
        }

        return temp.top();
    }
};