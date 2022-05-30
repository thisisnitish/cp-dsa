/*
Leetcode Question 88. Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/
*/

// Solution 1
class Solution
{
public:
    // Time: O(m+n)
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

// Solution 2 - Reverse merge sort
class Solution
{
public:
    // Time: O(m+n)
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i >= 0 and j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        while (i >= 0)
        {
            nums1[i] = nums1[k];
            i--;
            k--;
        }

        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
