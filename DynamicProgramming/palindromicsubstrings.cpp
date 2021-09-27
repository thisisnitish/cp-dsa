/*
Leetcode Question 647. Palindromic Substrings
https://leetcode.com/problems/palindromic-substrings/
*/

//Brute Force
class Solution
{
public:
    //Time: O(N^3)
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 1; j <= s.size() - i; j++)
            {
                string temp = s.substr(i, j);
                if (checkPalindrome(temp))
                    count++;
                temp.clear();
            }
        }
        return count;
    }

    bool checkPalindrome(string op)
    {
        if (op.size() == 0)
            return true;
        int i = 0, j = op.size() - 1;
        while (i < j)
        {
            if (op[i] != op[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

//Bottom Up Approacj
class Solution
{
public:
    //Time: O(N^2), Space: O(N^2)
    int countSubstrings(string s)
    {
        int count = 0;
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, 0));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < dp.size(); i++, j++)
            {
                if (gap == 0)
                {
                    //if the string contains single character
                    dp[i][j] = true;
                }
                else if (gap == 1)
                {
                    //string is of length 2 check both the characters, trivial case
                    if (s[i] == s[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else
                {
                    //if the string contains more than 2 characters then check for extreme
                    //characters and check if inner substring is palindrome or not
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                if (dp[i][j])
                    count++;
            }
        }
        return count;
    }
};
