/*
Leetcode Question 132. Palindrome Partitioning II
https://leetcode.com/problems/palindrome-partitioning-ii/
https://www.techiedelight.com/find-minimum-cuts-needed-palindromic-partition-string/
*/

//Recursive - TLE
class Solution
{
public:
    int minCut(string s)
    {
        return palindromePartition(s, 0, s.length() - 1);
    }

    int palindromePartition(string s, int i, int j)
    {
        if (i >= j)
            return 0;
        if (isPalindrome(s, i, j))
            return 0;

        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int tempAnswer = 1 + palindromePartition(s, i, k) + palindromePartition(s, k + 1, j);
            mn = min(mn, tempAnswer);
        }
        return mn;
    }

    bool isPalindrome(string s, int i, int j)
    {
        if (i == j)
            return true;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

//Memoization - TopDown - TLE
class Solution
{
public:
    int minCut(string s)
    {
        vector<vector<int> > dp(2001, vector<int>(2001, -1));
        int minPartition = palindromePartition(s, 0, s.length() - 1, dp);
        return minPartition;
    }

    int palindromePartition(string s, int i, int j, vector<vector<int> > &dp)
    {
        if (i >= j)
            return 0;
        if (isPalindrome(s, i, j))
        {
            dp[i][j] = 0;
            return 0;
        };
        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int tempAnswer = 1 + palindromePartition(s, i, k, dp) + palindromePartition(s, k + 1, j, dp);
            mn = min(mn, tempAnswer);
        }
        dp[i][j] = mn;
        return dp[i][j];
    }

    bool isPalindrome(string s, int i, int j)
    {
        if (i == j)
            return true;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

//Optimized Memoization - TLE
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
        int minPartition = palindromePartition(s, 0, n - 1, dp);
        return minPartition;
    }

    int palindromePartition(string &s, int i, int j, vector<vector<int> > &dp)
    {
        if (i >= j)
            return 0;
        if (isPalindrome(s, i, j) == true)
        {
            dp[i][j] = 0;
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {

            int left = 0, right = 0;
            if (dp[i][k] != -1)
                left = dp[i][k];
            else
            {
                left = palindromePartition(s, i, k, dp);
                dp[i][k] = left;
            }

            if (dp[k + 1][j] != -1)
                right = dp[k + 1][j];
            else
            {
                right = palindromePartition(s, k + 1, j, dp);
                dp[k + 1][j] = right;
            }
            int tempAnswer = 1 + left + right;
            if (tempAnswer < mn)
                mn = tempAnswer;
        }
        dp[i][j] = mn;
        return dp[i][j];
    }

    bool isPalindrome(string &s, int i, int j)
    {
        if (i == j)
            return true;
        if (i > j)
            return true;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

//Optimization with new approach - TLE
class Solution
{
public:
    //Time: O(N^3), Space: O(N^2)
    int minCut(string s)
    {
        int n = s.length();
        unordered_map<string, int> mp;
        vector<vector<bool> > isPalindrome(n, vector<bool>(n));
        findAllPalindrome(s, n, isPalindrome);
        return palindromePartition(0, n - 1, mp, isPalindrome);
    }

    void findAllPalindrome(string s, int n, vector<vector<bool> > &isPalindrome)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                    isPalindrome[i][j] = true;
                else if (s[i] == s[j])
                {
                    isPalindrome[i][j] = ((j - i == 1) ? true : isPalindrome[i + 1][j - 1]);
                }
                else
                {
                    isPalindrome[i][j] = false;
                }
            }
        }
    }

    int palindromePartition(int i, int j, unordered_map<string, int> &mp, vector<vector<bool> > &isPalindrome)
    {
        if (i >= j)
            return 0;
        if (isPalindrome[i][j])
        {
            return 0;
        };

        string key = to_string(i) + "|" + to_string(j);

        if (mp.find(key) == mp.end())
        {
            mp[key] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int tempAnswer = 1 + palindromePartition(i, k, mp, isPalindrome) + palindromePartition(k + 1, j, mp, isPalindrome);
                mp[key] = min(mp[key], tempAnswer);
            }
        }
        return mp[key];
    }
};

//More Optimzed with new approach - All test case passed
class Solution
{
public:
    //Time: O(N^2), Space: O(N)
    unordered_map<int, int> mp;
    int minCut(string s)
    {
        // for(auto m : mp)
        //     cout<<m.first<<" "<<m.second<<" ";
        return palindromePartition(s, 0) - 1;
    }

    int palindromePartition(string &s, int i)
    {
        if (i >= s.size())
            return 0;
        if (mp.count(i))
            return mp[i];

        int result = INT_MAX;
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                result = min(1 + palindromePartition(s, j + 1), result);
            }
        }
        return mp[i] = result;
    }

    bool isPalindrome(string &s, int i, int j)
    {
        if (i == j)
            return true;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
