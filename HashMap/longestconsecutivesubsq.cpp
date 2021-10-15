/*
Leetcode Question 128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/
*/

//Solution 1
class Solution
{
public:
    //Time: O(nlogn) Space: O(1)
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int maxLengthOfConsecutiveSeq = 0;
        int lengthSoFar = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] != nums[i])
            {
                if (nums[i - 1] + 1 == nums[i])
                    lengthSoFar++;
                else
                {
                    maxLengthOfConsecutiveSeq = max(maxLengthOfConsecutiveSeq, lengthSoFar);
                    lengthSoFar = 1;
                }
            }
        }
        return max(maxLengthOfConsecutiveSeq, lengthSoFar);
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(n) Space: O(1)
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        unordered_set<int> s;
        int maxLengthOfConsecutiveSeq = 0;

        for (auto x : nums)
            s.insert(x);

        for (auto item : s)
        {
            if (s.count(item - 1))
                continue; //if you found the element skip it

            int lengthSoFar = 1;
            while (s.count(item + lengthSoFar))
                lengthSoFar++;

            maxLengthOfConsecutiveSeq = max(maxLengthOfConsecutiveSeq, lengthSoFar);
        }
        return maxLengthOfConsecutiveSeq;
    }
};
