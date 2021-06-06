/*
Leetcode Question 347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/
*/

class Solution
{
public:
    //Time: O(nlogk), Space: O(n + k)
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        //using the min heap
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            pq.push({i->second, i->first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> kFrequent;
        while (pq.size() > 0)
        {
            kFrequent.push_back(pq.top().second);
            pq.pop();
        }
        return kFrequent;
    }
};