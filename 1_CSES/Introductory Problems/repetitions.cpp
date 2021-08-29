#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;

	int mx = 1, i=0;

	while(i < s.size()-1){
		int count = 1;
		while(s[i] == s[i+1]){
			i++;
			count++;
		}
		mx = max(mx, count);
		i++;
	}
	cout<<mx<<endl;
	return 0;
}
