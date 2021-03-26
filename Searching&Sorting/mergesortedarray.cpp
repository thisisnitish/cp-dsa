/*
Leetcode Question 88. Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/
*/

class Solution
{
public:
    /*the basic idea is to implement the merge part of the merge sort 
    algorithm. Time: O(N)*/
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m)
        {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < n)
        {
            result.push_back(nums2[j]);
            j++;
        }
        nums1 = result;
        result.clear();
    }
};