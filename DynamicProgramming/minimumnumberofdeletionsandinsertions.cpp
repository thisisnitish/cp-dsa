/*
Minimum number of deletions and insertions.
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1#
*/

class Solution
{
public:
    /*the basic idea is to find the lcs from both the strings and then 
	for deletion_count subtract from str1 length and for insertion_count
	subtract from str2 length and atlast add insertion and deletion
	Time: O(m*n), Space: O(m*n)*/
    int lcs(string &str1, string &str2, int m, int n, vector<vector<int> > &dp)
    {
        if (m == 0 || n == 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (str1[m - 1] == str2[n - 1])
            return dp[m][n] = 1 + lcs(str1, str2, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(lcs(str1, str2, m - 1, n, dp), lcs(str1, str2, m, n - 1, dp));
    }

    int minOperations(string str1, string str2)
    {
        //length of the strings
        int m = str1.size();
        int n = str2.size();

        //using memoization and initialized wiht -1
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));

        /*make sure to pass the string pass by reference not by value
	    because everytime we pass different local string to the function*/
        int deletion = m - lcs(str1, str2, m, n, dp);
        int insertion = n - lcs(str1, str2, m, n, dp);

        //atlast add the insertion and deletion
        return insertion + deletion;
    }
};
