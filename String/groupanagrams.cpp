/*
Leetcode Question 49. Group Anagrams
https://leetcode.com/problems/group-anagrams/
*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for (auto s : strs)
        {
            string c = s;
            sort(s.begin(), s.end());
            mp[s].push_back(c);
        }

        for (auto ele : mp)
        {
            result.push_back(ele.second);
        }
        return result;
    }
};