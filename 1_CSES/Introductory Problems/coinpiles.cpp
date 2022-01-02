#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1e9+7;
#define PI = 3.1415926535897932384626433832795;

void solve(){
	ll a, b;
	cin>>a>>b;

	bool caseI = ((2*a - b) >= 0) && ((2*a - b) % 3 == 0);
	bool caseII = ((2*b - a) >= 0) && ((2*b - a) % 3 == 0);
	if(caseI && caseII) cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
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