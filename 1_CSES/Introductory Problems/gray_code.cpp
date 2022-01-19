#include <bits/stdc++.h>
using namespace std;

vector<string> findGrayCode (int n){
	//base case
	if(n == 1){
		return {"0", "1"};
	}

	vector<string> previousGrayCode = findGrayCode(n-1);
	vector<string> currentGrayCode;

	//step 1: add 0s in front of all strings
	for(int i=0; i<previousGrayCode.size(); i++){
		currentGrayCode.push_back("0" + previousGrayCode[i]);
	}

	//step 2: add 1s in front of all strings from reverse
	for(int i = previousGrayCode.size()-1; i >= 0; i--){
		currentGrayCode.push_back("1" + previousGrayCode[i]);
	}
	return currentGrayCode;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
	
	int n;
	cin>>n;
	vector<string> result = findGrayCode(n);
	for(auto c : result){
		cout<<c<<endl;
	}
	return 0;
}
