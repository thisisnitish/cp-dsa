/*
Leetcode Question 215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        /*
        //Solution 1
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
        */

        //Solution 2
        priority_queue<int> pq;

        for (int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);

        //remove the k-1 elements from top
        for (int i = 0; i < k - 1; i++)
            pq.pop();

        //required element will come on top
        return pq.top();
    }
};