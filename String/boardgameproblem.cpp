//Cpp prgram for count the number of paths possible from start point to end point in gameboard

#include<iostream>
using namespace std;

int countPath(int start, int end){
    if(start == end) return 1;

    if(start > end) return 0;

    int count = 0;
    for(int i=0; i<=6; i++){
        count += countPath(start+i, end);
    }
    return count;
}


int main(){

    cout<<countPath(0, 3)<<endl;
    return(0);
}