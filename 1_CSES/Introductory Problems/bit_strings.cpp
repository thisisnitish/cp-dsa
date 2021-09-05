#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

//using binary exponentiation
/*
long long power(long long x, long long y){
	long long temp;
	if(y == 0) return 1;
	temp = power(x, y/2);
	long long result = (temp * temp) % mod;
	if(y % 2 == 1) result = (result * x) % mod;
	return result;
}

long long power(long long x, long long y){
	long long result = 1;
	while(b > 0){
		if(b % 2 == 1) result = (result * a) % mod;
		a = (a * a) % mod;
		b = b /2;
	}
	return result;
}
*/
int main(){
	long long n;
	cin>>n;

	long long res = 1;
	long long a = 2;
	while(n > 0){
		if(n % 2  == 1) res = (res * a) % mod;
		a = (a * a) % mod;
		n /= 2;
	}
	cout<<res<<endl;
	return 0;
}