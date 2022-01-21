/*
Leetcode Question 1980. Find Unique Binary String
https://leetcode.com/problems/find-unique-binary-string/
*/

class Solution
{
public:
    // Time: O(2^N)
    string res;
    bool ok = false;
    void findUniqueString(unordered_set<string> s, string str, int idx, int n)
    {
        // base case
        if (n == idx)
        {
            if (!s.count(str))
            {
                res = str;
                ok = true;
            }
            return;
        }

        if (!ok)
            findUniqueString(s, str + "0", idx + 1, n);
        if (!ok)
            findUniqueString(s, str + "1", idx + 1, n);
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<string> s(nums.begin(), nums.end());
        findUniqueString(s, "", 0, nums.size());
        return res;
    }
};
