#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, x;
	cin>>n>>x;

	vector<long long> v(n);
	for(int i=0; i<n; i++) cin>>v[i];

	sort(v.begin(), v.end());
	long long i = 0, j = n-1, count = 0;

	while(i <= j){
		if(v[i] + v[j] <= x) i++, j--, count++;
		else j--, count++;
	}
	cout<<count<<endl;
	return 0;
}
