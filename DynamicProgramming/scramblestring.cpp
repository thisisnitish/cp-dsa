/*
Leetcode Question 87. Scramble String
https://leetcode.com/problems/scramble-string/
*/

//Recursive
class Solution
{
public:
    /*just follow the question. Given string str, we can represent it 
    as a binary tree by partitioning it to two non-empty substrings recursively. 
    Time: O(2^N), Space: O(N)*/
    bool helper(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        if (s1 == s2 || s1.size() == 0)
            return true;

        int n = s1.size();

        //creating the unique key
        bool flag = false;
        for (int i = 1; i <= n - 1; i++)
        {

            //if there is swapping in the string
            bool caseI = helper(s1.substr(0, i), s2.substr(n - i, i)) &&
                         helper(s1.substr(i, n - i), s2.substr(0, n - i));

            //if there is no swapping in the string
            bool caseII = helper(s1.substr(0, i), s2.substr(0, i)) &&
                          helper(s1.substr(i, n - i), s2.substr(i, n - i));

            if (caseI || caseII)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }

    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        return helper(s1, s2);
    }
};

//Memoized - BottomUp
class Solution
{
public:
    unordered_map<string, bool> mp;
    bool helper(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        if (s1 == s2 || s1.size() == 0)
            return true;

        int n = s1.size();

        //creating the unique key
        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end())
            return mp[key];

        bool flag = false;
        for (int i = 1; i <= n - 1; i++)
        {

            //if there is swapping in the string
            bool caseI = helper(s1.substr(0, i), s2.substr(n - i, i)) &&
                         helper(s1.substr(i, n - i), s2.substr(0, n - i));

            //if there is no swapping in the string
            bool caseII = helper(s1.substr(0, i), s2.substr(0, i)) &&
                          helper(s1.substr(i, n - i), s2.substr(i, n - i));

            if (caseI || caseII)
            {
                flag = true;
                break;
            }
        }
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
