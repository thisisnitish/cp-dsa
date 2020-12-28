// CPP program for permutations of a string
/*
input
ABC

output
All possbile permutations
ABC
ACB
BAC
BCA
CAB
CBA
*/


#include <iostream>
#include <string>
using namespace std;

void permutation(string s, string ans){
    
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }

    //take every character from the string and apply recursion on the rest of the string
    for (int i = 0; i < s.length(); i++){
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i+1);   //rest of string

        permutation(ros, ans+ch);
    }
}

int main(){
    permutation("ABC", "");
    return(0);
}