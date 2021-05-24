/*
N meetings in one room
https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
*/

class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int> > activity;
        for (int i = 0; i < n; i++)
        {
            activity.push_back({start[i], end[i]});
        }

        sort(activity.begin(), activity.end(), [&](vector<int> &a, vector<int> &b){ 
            return a[1] < b[1]; 
        });

        int noOfActivities = 1;
        int done = activity[0][1];
        for (int i = 1; i < n; i++)
        {
            if (activity[i][0] > done)
            {
                noOfActivities++;
                done = activity[i][1];
            }
        }
        return noOfActivities;
    }
};
