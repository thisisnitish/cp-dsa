#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long sum = (n * (n+1))/2;
	if(sum % 2 != 0) cout<<"NO"<<endl;
	else{
		vector<long long> v1, v2;
		sum = sum /2;
		while(n){
			if(sum - n >= 0){
				v1.push_back(n);
				sum = sum - n;
			}
			else{
				v2.push_back(n);
			}
			n--;
		}

		cout<<"YES"<<endl;
		cout<<v1.size()<<endl;
		for(auto e : v1){
			cout<<e<<" ";
		}
		cout<<endl;
		cout<<v2.size()<<endl;
		for(auto e : v2){
			cout<<e<<" ";
		}
		cout<<endl;
	}	
	return 0;
}