//CPP prorgram to solve the rat in a maze problem
//Rat can move in right and downward direction only

/*
input: 
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

output:
1 0 0 0 0                                                                                                                              
1 1 1 1 0                                                                                                                              
0 0 0 1 0                                                                                                                              
0 0 0 1 1                                                                                                                              
0 0 0 0 1  
*/

#include <iostream>
using namespace std;

//function to tell that rat can go to a particular position or not
//if position is valid return true otherwise return false
bool isSafe(int** arr, int x, int y, int n){
    if(x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}

bool ratInMaze(int** arr, int x, int y, int n, int** solArr){

    //this is our base case i.e. the position should be less than n
    if(x == n-1 && y == n-1){
        solArr[x][y] = 1;
        return true;
    }

    if(isSafe(arr, x, y, n)){
        solArr[x][y] = 1;
        
        //rat going to the forward direction
        if(ratInMaze(arr, x+1, y, n, solArr)){
            return true;
        }

        /*if rat fails in forward direction then 
        move to the downward direction*/
        if(ratInMaze(arr, x, y+1, n, solArr)){
            return true;
        }

        /*if none of the avobe solutions work then reset 
        the solution and backtrack to the original position*/
        solArr[x][y] = 0;     //reset the solution i.e. backtracking
        return false;
    }
    return false;
}

int main(){

    int n;
    cin>>n;

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int** solArr = new int*[n];
    for(int i=0; i<n; i++){
        solArr[i] = new int[n];
        for(int j=0; j<n; j++){
            solArr[i][j] = 0;
        }
    }

    if(ratInMaze(arr, 0, 0, n, solArr)){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
