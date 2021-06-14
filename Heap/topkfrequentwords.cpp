/*
Leetcode Question 692. Top K Frequent Words
https://leetcode.com/problems/top-k-frequent-words/
*/

/*
The idea is to put all the elements of the vector in the map with their frequency counts.
Since we want top k frequent words which means k words which has maximum frequency that 
means we need to keep the words which has maximum frequency which means we need to use min 
heap.

Since the question's twist is when two words have same frequency then choose the word which
has lower alphabetical order that means we need to define a comparator function and it will
be repsonsible for the order in min heap. Always remember, the main thing about this question
is ordering of the elements.
for ex - string a, string b and their frequency is 3 and 5 respectively
Custom comparator function will look like this,
if(freq of a != freq of b) 
    return freq of a > freq of b;
else 
    return string a < string b;

Also, we need k frequent words that means, we will pop the elements from the min heap as it's
size will be more than k
*/

class Solution
{
public:
    //Time: O(nlogk), Space: O(n+k)
    struct myComp
    {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        {
            if (a.first != b.first)
                return a.first > b.first;
            else
                return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++)
            mp[words[i]]++;

        priority_queue<pair<int, string>, vector<pair<int, string> >, myComp> pq;

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            pq.push({i->second, i->first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> kFrequent;

        while (pq.size() > 0)
        {
            kFrequent.push_back(pq.top().second);
            pq.pop();
        }
        reverse(kFrequent.begin(), kFrequent.end());
        return kFrequent;
    }
};
