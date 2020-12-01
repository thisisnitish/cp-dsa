/*
Leetcode Question 287. Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number/
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        //Time: O(n), Space: O(n)
        set<int> s;

        for (int i = 0; i < nums.size(); i++){
            if (s.find(nums[i]) == s.end())
                s.insert(nums[i]);
            else
                return nums[i];
        }
        return false;
    }
};

//Todo: Convert this problem into Linked List Cycle problem