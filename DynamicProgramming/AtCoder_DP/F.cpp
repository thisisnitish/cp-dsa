/*
Link: https://atcoder.jp/contests/dp/tasks/dp_f
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<vector<int> > memo;

int longestCommonSubsequence(string &s, string &t, int m, int n){
    if (m == 0 || n == 0)
        return 0;

    if (memo[m][n] != -1)
        return memo[m][n];

    if (s[m - 1] == t[n - 1])
        return memo[m][n] = 1 + longestCommonSubsequence(s, t, m - 1, n - 1);
    else
        return memo[m][n] = max(longestCommonSubsequence(s, t, m - 1, n), longestCommonSubsequence(s, t, m, n - 1));
}

string printLongestCommonSubsequence(string s, string t, int m, int n){
    string res;
    int i = m, j = n;

    while (i > 0 && j > 0){
        if (s[i - 1] == t[j - 1]){
            res.push_back(s[i - 1]);
            i--;
            j--;
        }
        else{
            if (memo[i][j - 1] > memo[i - 1][j])
                j--;
            else
                i--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string s, t;
    cin >> s;
    cin >> t;

    int m = s.size();
    int n = t.size();

    memo.resize(m + 1, vector<int>(n + 1, -1));
    longestCommonSubsequence(s, t, m, n);
    string res = printLongestCommonSubsequence(s, t, m, n);

    for (int i = 0; i < res.size(); i++){
        cout << res[i];
    }
    cout << endl;
    return (0);
}
