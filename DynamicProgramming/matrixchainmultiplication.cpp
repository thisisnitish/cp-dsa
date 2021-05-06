/*CPP code for matrix chain multiplication
Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which order 
to perform the multiplications.

Input:
Enter the size of the array: 5
Enter the array elements: 1 2 3 4 3

Output:
Minimum number of multiplications: 30

Input:
Enter the size of the array: 5
Enter the array elements: 40 20 30 10 30

Output:
Minimum number of multiplications: 26000
*/

//Recursive
#include<iostream>
#include<vector>
using namespace std;

int matrixChainMultiplication(vector<int>& arr, int i, int j){
    if(i >= j) return 0;

    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tempAnswer = matrixChainMultiplication(arr, i, k) + matrixChainMultiplication(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);

        if(tempAnswer < mn)
            mn = tempAnswer;
    }
    return mn;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr;
    cout<<"\nEnter the array elements: ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int minNoOfMultiplication = matrixChainMultiplication(arr, 1, n-1);
    cout << "Minimum number of multiplications: " << minNoOfMultiplication << "\n";
    return 0;
}


//Memoization
#include<iostream>
#include<vector>
using namespace std;

int matrixChainMultiplication(vector<int>& arr, int i, int j, vector<vector<int> >& dp){
    if(i >= j) return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tempAnswer = matrixChainMultiplication(arr, i, k, dp) + matrixChainMultiplication(arr, k+1, j, dp) + (arr[i-1] * arr[k] * arr[j]);

        if(tempAnswer < mn)
            mn = tempAnswer;    
    }
    dp[i][j] = mn;
    return dp[i][j];
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr;
    cout<<"\nEnter the array elements: ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    //let suppose the constraint is 100
    vector<vector<int> > dp(101, vector<int>(101, -1));
    int minNoOfMultiplication = matrixChainMultiplication(arr, 1, n-1, dp);
    cout<<"Minimum number of multiplications: "<<minNoOfMultiplication<<"\n";
    return 0;
}

