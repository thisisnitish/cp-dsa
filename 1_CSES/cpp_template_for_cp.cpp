#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>
// #include <queue>
// #include <algorithm>
using namespace std;

#define ll long long
#define MOD 1e9+7;
#define PI = 3.1415926535897932384626433832795;

int gcd(ll a, ll b);

void solve(){
	
}

int gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll t;
	cin>>t;

	while(t){
		solve();
		t--;
	}
	return 0;
}