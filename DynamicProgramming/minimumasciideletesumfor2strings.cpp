/*
Leetcode Question 712. Minimum ASCII Delete Sum for Two Strings
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
*/

/*
Brute Force aprroach: Find the LCS and then print it i.e. find the common subsequence
string. Then find the sum of the subsequence string. Find the sum of s1 chars and s2 chars
after that add those sums and after that subtract the lcs sum from that sum. Below Formula
sum(s1) + sum(s2) - 2*sum(lcs)

But we can optimize this approach, we don't need to print the lcs.
Since we know that our table stores the length of longest subsequence till specific index.
Instead of the length, we can store the sum of ascii characters till that index.
*/

//Recursive
class Solution
{
public:
    //Time: O(2^n)
    int minimumDeleteSum(string s1, string s2)
    {
        int sum1 = 0, sum2 = 0;

        //calculating the sum of the strings
        for (auto c : s1)
            sum1 += c;

        for (auto c : s2)
            sum2 += c;

        int m = s1.size();
        int n = s2.size();
        return sum1 + sum2 - 2 * lcs(s1, s2, m, n);
    }

    int lcs(string s1, string s2, int m, int n)
    {
        //base condition
        if (m == 0 || n == 0)
            return 0;

        /*if the chars are same return that ascii value which 
         is same and move to the next chars*/
        if (s1[m - 1] == s2[n - 1])
            return s1[m - 1] + lcs(s1, s2, m - 1, n - 1);
        else //if not then we will have two possibilities
            return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
};

//Recursive + Memoization, TopDown Approach
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    vector<vector<int> > memo;
    int minimumDeleteSum(string s1, string s2)
    {
        int sum1 = 0, sum2 = 0;

        //calculating the sum of the strings
        for (auto c : s1)
            sum1 += c;

        for (auto c : s2)
            sum2 += c;

        int m = s1.size();
        int n = s2.size();
        memo.resize(m + 1, vector<int>(n + 1, -1));
        return sum1 + sum2 - 2 * lcs(s1, s2, m, n);
    }

    int lcs(string &s1, string &s2, int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;

        if (memo[m][n] != -1)
            return memo[m][n];

        /*if the chars are same then store the ascii value with the sum of prev one and
         then call for the next chars and return it*/
        if (s1[m - 1] == s2[n - 1])
            return memo[m][n] = s1[m - 1] + lcs(s1, s2, m - 1, n - 1);
        else //if not then we will have two possibilities
            return memo[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
};

//Bottom Up Approach
class Solution
{
public:
    //Time: O(m*n), Space: O(m*n)
    int minimumDeleteSum(string s1, string s2)
    {
        int sum1 = 0, sum2 = 0;

        for (auto c : s1)
            sum1 += c;

        for (auto c : s2)
            sum2 += c;

        int m = s1.size();
        int n = s2.size();

        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

        //initialzing
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        //solving the subproblems
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int lcs = dp[m][n];
        return sum1 + sum2 - 2 * lcs;
    }
};
