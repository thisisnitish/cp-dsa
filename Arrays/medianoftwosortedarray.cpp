/*
Leetcode Question 4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> temp;

        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;

        while (i < m && j < n){
            if (nums1[i] <= nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m){
            temp.push_back(nums1[i]);
            i++;
        }
        while (j < n){
            temp.push_back(nums2[j]);
            j++;
        }

        int l = temp.size();
        double sum = 0, median = 0;
        if (l % 2 == 0){
            int idx = l / 2;
            sum = temp[idx] + temp[idx - 1];
            median = sum / 2;
        }
        else{
            int idx = l / 2;
            median = temp[idx];
        }
        return median;
    }
};