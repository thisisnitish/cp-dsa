/*
Leetcode Question 87. Scramble String
https://leetcode.com/problems/scramble-string/
*/

/*
just follow the question. Given string str, we can represent it as a binary tree by
partitioning it to two non-empty substrings recursively.
*/

// Recursive
class Solution
{
public:
    // Time: O(N*(2^N + 2^N)), Space: O(N)
    bool helper(string s1, string s2)
    {

        // if both the strings are equal
        if (s1 == s2)
            return true;

        // if at any point, we encounter an empty string return false
        if (s1.size() <= 1)
            return false;

        int n = s1.size();

        bool flag = false;
        for (int i = 1; i <= n - 1; i++)
        {

            // if there is swapping in the string
            bool caseI = helper(s1.substr(0, i), s2.substr(n - i, i)) &&
                         helper(s1.substr(i, n - i), s2.substr(0, n - i));

            // if there is no swapping in the string
            bool caseII = helper(s1.substr(0, i), s2.substr(0, i)) &&
                          helper(s1.substr(i, n - i), s2.substr(i, n - i));

            // if the string is scrambled immediately return true
            if (caseI || caseII)
            {
                flag = true;
                break;
            }
        }
        // if the string is not scrambled return false
        return flag;
    }

    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        return helper(s1, s2);
    }
};

// Memoized - BottomUp
class Solution
{
public:
    // Time: O(N^3), Space: O(N)
    unordered_map<string, bool> mp;
    bool helper(string s1, string s2)
    {

        // if both the strings are equal
        if (s1 == s2)
            return true;

        // if at any point, we encounter an empty string return false
        if (s1.size() <= 1)
            return false;

        int n = s1.size();

        // creating the unique key
        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end())
            return mp[key];

        bool flag = false;
        for (int i = 1; i <= n - 1; i++)
        {

            // if there is swapping in the string
            bool caseI = helper(s1.substr(0, i), s2.substr(n - i, i)) &&
                         helper(s1.substr(i, n - i), s2.substr(0, n - i));

            // if there is no swapping in the string
            bool caseII = helper(s1.substr(0, i), s2.substr(0, i)) &&
                          helper(s1.substr(i, n - i), s2.substr(i, n - i));

            // if the string is scrambled immediately return true
            if (caseI || caseII)
            {
                flag = true;
                break;
            }
        }
        // if the string is not scrambled return false
        mp[key] = flag;
        return flag;
    }

    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        return helper(s1, s2);
    }
};
