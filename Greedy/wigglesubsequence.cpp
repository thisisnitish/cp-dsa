/*
Leetcode Question 376. Wiggle Subsequence
https://leetcode.com/problems/wiggle-subsequence/
*/

class Solution
{
public:
    // Time: O(N), Space: O(N)
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();

        int prev = nums[1] - nums[0];
        int diff = prev;
        int count = prev != 0 ? 2 : 1;

        for (int i = 2; i < nums.size(); i++)
        {
            diff = nums[i] - nums[i - 1];
            if ((prev >= 0 && diff < 0) || (prev <= 0 && diff > 0))
            {
                count++;
                prev = diff;
            }
        }
        return count;
    }
};
