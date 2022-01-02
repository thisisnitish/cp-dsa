//This is variation of finding the permutations of a string
#include <bits/stdc++.h>
using namespace std;

set<string> res;
void generatePermutations(string& s, int idx){
	//base case
	if(s.size() == idx){
		res.insert(s);
		return;
	}

	for(int i=idx; i<s.size(); i++){
		swap(s[idx], s[i]);		//swapping the number to generate permutation
		generatePermutations(s, idx+1);
		swap(s[idx], s[i]);		//swapping again for backtacking
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
	string s;
	cin>>s;

	generatePermutations(s, 0);

	cout<<res.size()<<endl;
	for(auto c : res){
		cout<<c<<endl;
	}
	return 0;
}
