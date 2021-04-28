/*CPP code for printing the longest common subsquence
Given two sequences, print the longest subsequence present in both of them.
The basic idea is we know how to find the length of the LCS. And using bottom up approach, we also
know how to find that LCS where we creat table "dp". Now, using that table we can find the string 
but in a reversed order. So, after getting the string we have to reverse the string.

How we will get the string from the table
Traverse the 2D array dp from last dp[m][n].
a. check if corresponding characters are equal then include into the lcs
b. Else compare values dp[i-1][j] and dp[i][j-1], find the maximum value and move towards that direction

In this way we will get the string but in reversed order, so atlast we have to reverse it

Input:
Enter the first string: AGGTAB
Enter the second string: GXTXAYB

Output:
Longest Common Subsequence is: GTAB

Input:
Enter the first string: acbcf
Enter the second string: abcdaf

Output:
Longest Common Subsequence is: abcf

Time: O(m*n)
Space: O(m*n)
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


string printLongestCommonSubsequence(vector<vector<int> >& dp, int m, int n, string text1, string text2){
    int i = m, j = n;
    string lcs = "";
    while(i > 0 && j > 0){
        if(text1[i-1] == text2[j-1]){
            lcs.push_back(text1[i-1]);
            i--; j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j]) j--;
            else i--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

string longestCommonSubsequence(string text1, string text2){
    int m = text1.size();
    int n = text2.size();
    vector<vector<int> > dp(m+1, vector<int>(n+1));

    //initialization
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
    }

    //solving the subproblems to solve the bigger problems
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return printLongestCommonSubsequence(dp, m, n, text1, text2);
}

int main(){
    string text1, text2;
    cout<<"Enter the first string: ";
    cin>>text1;
    cout<<"\nEnter the second string: ";
    cin>>text2;

    string lcs = longestCommonSubsequence(text1, text2);
    cout<<"Longest Common Subsequence is: "<<lcs<<endl;
    return(0);
}
