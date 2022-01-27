#include <bits/stdc++.h>
using namespace std;

/*
//Recursive + Memoization
int editDistance(string& s1, string& s2, int m, int n, vector<vector<int>>& memo){
	if(m == 0) return memo[m][n] = n;
	if(n == 0) return memo[m][n] = m;

	if(memo[m][n] != -1) return memo[m][n];

	if(s1[m-1] == s2[n-1])
		return memo[m][n] = editDistance(s1, s2, m-1, n-1, memo);
	else{
		int insertChars = editDistance(s1, s2, m, n-1, memo);
		int deleteChars = editDistance(s1, s2, m-1, n, memo);
		int removeChars = editDistance(s1, s2, m-1, n-1, memo);

		return memo[m][n] = 1 + min({ insertChars, deleteChars, removeChars });
	}
}
*/
//Tabulation - Bottom Up
int editDistance(string s1, string s2, int m, int n){
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	//initialzing the base case
	for(int j=0; j<n+1; j++)
		dp[0][j] = j;

	for(int i=0; i<m+1; i++)
		dp[i][0] = i;
	
	//solving the subproblems
	for(int i=1; i<m+1; i++){
		for(int j=1; j<n+1; j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = 1 + min({ dp[i][j-1], dp[i-1][j], dp[i-1][j-1] });
			}
		}
	}
	return dp[m][n];
}

int main(){
	string s1, s2;
	cin>>s1;
	cin>>s2;

	int m = s1.size();
	int n = s2.size();

	// vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
	// cout<<editDistance(s1, s2, m, n, memo)<<endl;
	cout<<editDistance(s1, s2, m, n)<<endl;
	return 0;
}
