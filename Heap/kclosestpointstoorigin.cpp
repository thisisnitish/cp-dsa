/*
Leetcode Question 973. K Closest Points to Origin
https://leetcode.com/problems/k-closest-points-to-origin/
*/

class Solution
{
public:
    //Time: O(nlogk), Space: O(k)
    vector<vector<int> > kClosest(vector<vector<int> > &points, int K)
    {
        priority_queue<pair<int, vector<int> > > maxHeap;

        for (int i = 0; i < points.size(); i++)
        {
            //calculating the distance
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({dist, points[i]});

            if (maxHeap.size() > K)
                maxHeap.pop();
        }

        vector<vector<int> > result;
        while (maxHeap.size() > 0)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
