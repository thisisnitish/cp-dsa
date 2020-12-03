/*
Leetcode Question 56. Merge Intervals
https://leetcode.com/problems/merge-intervals/
*/

class Solution
{
public:
    //O(nlogn)
    //Todo: why put static
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        // if(intervals.size() <= 1)
        //     return intervals;

        sort(intervals.begin(), intervals.end(), comp);
        int index = 0;

        for (int i = 1; i < intervals.size(); i++){
            //overlap situation
            if (intervals[index][1] >= intervals[i][0]){
                intervals[index][0] = min(intervals[index][0], intervals[i][0]);
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            }
            else{
                ++index;
                intervals[index] = intervals[i];
            }
        }

        vector<vector<int>> result;

        for (int i = 0; i <= index; i++){
            result.push_back(intervals[i]);
        }

        return result;
    }
};