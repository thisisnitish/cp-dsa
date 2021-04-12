/*CPP code for Partition a set into two subsets such that the difference of subset sums is minimum
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference
between their sums is minimum. If there is a set S with n elements, then if we assume Subset1 has m elements,
Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
---------------------------------------------------------------------------------------------------------
--> The basic idea is that we are using the subset sum problem to solve this problem. We don't have sum in this question
so we have to calculate sum and then after that follow the subet sum problem and create a table. But we only want the
last row of that table till sum/2 beacuse eg. s2-s1 should be minimum so for that we are keeping the s1 as minimum but
till sum/2 and we are sure that s1 will lie in 0 to sum(say range).

--> We will use a vector and push only those sum i.e. s1 till sum/2 which will exist (only true value) and then after
that we subtract from range to get the s2 and we have to find the minimum s2 then only we will be able to minimum subset 
difference.

--> The formula is min = S2 - S1 => Sum - S1 - S1 => Sum - 2*S1
Input:
Enter the size of the array: 4
1 6 11 5
Output:
Minimum Subset Difference is: 1

Input:
Enter the size of the array: 3
1 2 7
Output:
Minimum Subset Difference is: 4

Time: O(sum*n)
Space: O(sum*n)
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> subsetSum(vector<int>& arr, int sum, int n){
    vector<vector<bool> > dp(n+1, vector<bool>(sum+1));

    //initializing
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i == 0) dp[i][j] = false;
            if(j == 0) dp[i][j] = true;
        }
    }

    //solving the smaller problems
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    //taking the last row as it is required only
    //only push those sums which exists i.e. only true value
    vector<int> v;
    for(int i = 0; i<=sum/2; i++){
        if(dp[n][i]){
            v.push_back(i);
        }
    }
    return v;
}

int main(){
    int n, sum=0;
    cout << "\nEnter the size of the array: ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    //finding the sum
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    vector<int> v = subsetSum(arr, sum, n);
    int mn = INT_MAX;
    for(int j=0; j<v.size(); j++){
        //just applying the formula
        mn = min(mn, sum - 2*v[j]);
    }
    cout<<"Minimum Subset Difference is: "<<mn<<endl;
    return 0;
}
