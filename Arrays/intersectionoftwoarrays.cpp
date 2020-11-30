/*
Leetcode Question 349. Intersection of Two Arrays
https://leetcode.com/problems/intersection-of-two-arrays/
*/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        //Time: O(n)
        set<int> s1;
        set<int> s2;
        vector<int> result;

        //insert all the unique values to the set
        for (int i = 0; i < nums1.size(); i++)
            s1.insert(nums1[i]);

        //check all the element from nums2 that are present in s1
        //and put in the s2
        for (int i = 0; i < nums2.size(); i++){
            if (s1.find(nums2[i]) != s1.end())
                s2.insert(nums2[i]);
        }

        //push the elements from set to the vector
        set<int>::iterator itr;
        for (itr = s2.begin(); itr != s2.end(); itr++)
            result.push_back(*itr);

        return result;
    }
};