/*
Game with String 
https://practice.geeksforgeeks.org/problems/game-with-string4100/1#
*/

class Solution
{
public:
    /*the basic idea is to have count of each characters
    use pq(max-heap) to store the count, then pop the values
    k times after that at last pop every values and add the square
    of it. Time: O(N), Space: O(N)*/
    int minValue(string s, int k)
    {
        // code here
        if (k >= s.size())
            return 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        priority_queue<int> pq;

        for (auto i : mp)
        {
            pq.push(i.second);
        }

        while (k--)
        {
            int x = pq.top();
            pq.pop();
            x--;
            pq.push(x);
        }

        int result = 0;
        while (!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            result += x * x;
        }

        return result;
    }
};
