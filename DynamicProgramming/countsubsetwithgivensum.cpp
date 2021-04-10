/*Cpp code for Count of Subset with given Sum
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.
The basic idea is if you have done subset sum problem then this problem is easy for you
because here we are using the same code but in place of '||' we are using '+' in function. The reason we are using
'+' because in subset sum we have been told to print the true or false if we get the subset and don't check further 
but here we have to check all possible combinations. We don't have to stop even if we find the one subset with 
given sum, we have to check for all.
Input:
Enter the size of the array: 4
3 3 3 3
Enter the sum: 6
Output:
6

Input:
Enter the size of the array: 6
2 3 5 6 8 10
Enter the sum: 10
Output:
3
Time: O(n*sum)
Space: O(n*sum)
*/
#include<iostream>
#include<vector>
using namespace std;

int subsetSum(vector<int>& arr, int n, int sum){
    vector<vector<int> > dp(n+1, vector<int>(sum+1));

    //initializing
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    //solving the small problems and finding the big problem
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n, sum;
    cout << "\nEnter the size of the array: ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "\nEnter the sum: ";
    cin >> sum;
    int countSubsets = subsetSum(arr, n, sum);
    cout<<countSubsets<<endl;
    return 0;
}
