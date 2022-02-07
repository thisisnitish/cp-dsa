#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	if(n == 1){
		cout<<1<<endl;
	}
	else if(n == 2 || n == 3){
		cout<<"NO SOLUTION"<<endl;
	}
	else if(n == 4){
		cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl;
	}
	else{
		vector<int> odd, even;
		for(int i=1; i<=n; i++){
			if(i % 2 == 0) even.push_back(i);
			else odd.push_back(i);
		}
		for(auto x : odd) cout<<x<<" ";

		for(auto x : even) cout<<x<<" ";
	}
	return 0;
}
