/*CPP code for Subset Sum problem
Given a set of non-negative integers, and a value sum, determine if there 
is a subset of the given set with sum equal to given sum. We have used Top Down Approach for implementation
The basic idea is we can do this with the 0/1 knapsack top down code with some modification
If you look at the code of kanpsack implementation with top dowm approach the code is similar
and if you already understood the 0/1 knapsack problem then this question is easy for you
Input:
Enter the size of the array: 5
2 3 7 8 10
Enter the sum: 11

Output:
Found a subset with given sum

Input:
Enter the size of the array: 6
3 34 4 12 5 2
Enter the sum: 30

Output:
No subset with given sum

Time: O(N*sum)
Space: O(N*sum)
*/

#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(vector<int>& arr, int sum, int n){
    vector<vector<int> > t(n+1, vector<int> (sum+1));

    //initialization
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    }

    //finding the subset sum
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main(){
    int n, sum;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"\nEnter the sum: ";
    cin>>sum;
    if(subsetSum(arr, sum, n)){
        cout<<"\nFound a subset with given sum";
    }
    else
        cout<<"\nNo subset with given sum";
    
    return 0;
}
