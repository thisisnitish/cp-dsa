#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;

	vector<long long> v;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}

	/*another method is to use map but that will give you TLE in 2 cases*/
	sort(v.begin(), v.end());
	int count = 1;
	for(int i=0; i<n-1; i++){
		if((v[i+1] - v[i])>= 1) count++;
	}
	cout<<count<<endl;
	return 0;
}

