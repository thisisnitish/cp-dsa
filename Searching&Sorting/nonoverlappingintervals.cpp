/*
Leetcode Question 435. Non-overlapping Intervals
https://leetcode.com/problems/non-overlapping-intervals/
*/

class Solution
{
public:
    // Time: O(NLogN), Space: O(N)
    int eraseOverlapIntervals(vector<vector<int> > &intervals)
    {
        int n = intervals.size();
        if (n == 1)
            return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int endOfPrevious = intervals[0][1];
        int removeIntervals = 0;
        for (int i = 1; i < n; i++)
        {
            if (endOfPrevious <= intervals[i][0])
                endOfPrevious = intervals[i][1];
            else
                removeIntervals++;
        }
        return removeIntervals;
    }
};
