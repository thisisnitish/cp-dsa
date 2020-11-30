/*
Leetcode Question 350. Intersection of Two Arrays II
https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> result;

        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j]){
                j++;
            }
            else
                i++;
        }
        return result;
    }
};