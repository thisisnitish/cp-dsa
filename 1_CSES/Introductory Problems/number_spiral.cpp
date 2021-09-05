#include <iostream>
using namespace std;

int main(){
	long long  t;
	cin>>t;

	while(t--){
		long long x, y;
		cin>>x>>y;

		if(y > x){
			if(y% 2 == 1){
				long long ans = (y*y) - x + 1;
				cout<<ans<<endl;
			}
			else{
				long long ans  = ((y-1) * (y-1)) + x;
				cout<<ans<<endl;
			}
		}
		else{
			if(x % 2 == 1){
				long long ans = ((x-1) * (x-1)) + y;
				cout<<ans<<endl;
			}
			else{
				long long ans = (x*x)- y + 1;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
