/*
Leetcode Question 392. Is Subsequence
https://leetcode.com/problems/is-subsequence/
*/


//using DP
class Solution {
public:
    /*Time: O(m*n), Space: O(m*n)*/
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int subsequenceLength = lcs(s, t, m, n, dp);
        int isSubsequence = subsequenceLength == m;
        return isSubsequence;
    }
    
    int lcs(string& s, string& t, int m, int n, vector<vector<int>>& dp){
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s[m-1] == t[n-1])
            return dp[m][n] = 1 + lcs(s, t, m-1, n-1, dp);
        else
            return dp[m][n] = max(lcs(s, t, m-1, n, dp), lcs(s, t, m, n-1, dp));
    }
};

//Normal Logic
class Solution {
public:
    /*Time: O(n)*/
    bool isSubsequence(string s, string t) {
        int n = t.length();
        int idx = 0;
        for(int i=0; i<n; i++){
            if(t[i] == s[idx])
                idx++;
        }
        return(idx == s.length());
    }
};