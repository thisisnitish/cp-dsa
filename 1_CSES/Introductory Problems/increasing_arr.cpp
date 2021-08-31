#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, x;
	cin>>n;

	long long count = 0;
	vector<long long> v;
	for(int i=0; i<n; i++){
		cin>>x;
		v.push_back(x);
	}

	for(int i=1; i<v.size(); i++){
		if(v[i] < v[i-1])
			if(abs(v[i] - v[i-1]) >= 1){
				count += abs(v[i] - v[i-1]);
				v[i] = v[i] + abs(v[i] - v[i-1]);
			}
	}
	cout<<count<<endl;
	return 0;
}
