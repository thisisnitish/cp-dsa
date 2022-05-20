/*
Leetcode Question 49. Group Anagrams
https://leetcode.com/problems/group-anagrams/
*/

/*
It was very simple implementation of hashing. Now, new concepts I learned in this
question.
I was able to do it in 7 mins. 59 sec.
*/

class Solution
{
public:
    // Time: O(n * m.logm + n), Space: O(n)
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // base case
        if (strs.size() == 1)
        {
            if (strs[0] == "")
                return {{""}};
            else
                return {{strs[0]}};
        }

        unordered_map<string, vector<string>> mp;
        for (auto s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &[k, v] : mp)
        {
            result.push_back(v);
        }
        return result;
    }
};
