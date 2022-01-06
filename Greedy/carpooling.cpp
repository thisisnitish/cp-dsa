/*
Leetcode Question 1094. Car Pooling
https://leetcode.com/problems/car-pooling/
*/

class Solution
{
public:
    // Time: O(N), Space: O(N)
    bool carPooling(vector<vector<int> > &trips, int capacity)
    {
        vector<pair<int, int> > v;

        for (auto trip : trips)
        {
            v.push_back({trip[1], trip[0]});
            v.push_back({trip[2], -trip[0]});
        }

        sort(v.begin(), v.end());
        int seatsFilled = 0;
        for (int i = 0; i < v.size(); i++)
        {
            seatsFilled += v[i].second;
            if (seatsFilled > capacity)
                return false;
        }
        return true;
    }
};

