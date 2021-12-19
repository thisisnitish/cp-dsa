#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1e9+7;
#define PI = 3.1415926535897932384626433832795;

void solve(){
	ll a, b;
	cin>>a>>b;

	if(a == b){
		if(a == 0 and b == 0){
			cout<<"YES"<<endl;
		}
		else if(a % 2 == 0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	else{
		while(a != 0 and b != 0){
			if(a > b){
				a = a - 2;
				b = b - 1;
			}
			else{
				a = a - 1;
				b = b - 2;
			}

			if(a == 0 and b == 0){
				cout<<"YES"<<endl;
				break;
			}

			if(a == b){
				if(a % 2 == 0){
					cout<<"NO"<<endl;
					break;
				}
				else{
					cout<<"YES"<<endl;
					break;
				}
			}
		}

		if(a == 0 and b == 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
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