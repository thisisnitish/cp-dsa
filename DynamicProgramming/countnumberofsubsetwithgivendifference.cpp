/*CPP code for Count the number of subset with given difference
Question is, we have given an array and a difference and we have to count the number of subsets with
that given difference.
The basic idea is we have difference and we can calculate the sum of the array and the question is
asking count of s2-s1 = diff. So,
    sumof(subset1) - sumof(subset2) = diff
    sumof(subset1) + sumof(subset2) = sumof(arr)
  ------------------------------------------------
    sumof(subset1) = (diff + sumof(arr)) / 2

So, this means that we need to count the number of subsets with sumof(subset1) because the above formula is
valid. If we have sumof(subset1) then we can find the sumof(subset2) with the help of first equation.

So, All in all we have to count the number of subsets for sumof(subset1). This means,
this problem is reduced from "Count the number of subset with given difference" to "Count of Subset with given Sum"

Input:
Enter the size of the array: 4
1 1 2 3
Enter the difference: 1

Output:
3

Time: O(n*sum)
Space: O(n*sum)
*/

#include<iostream>
#include<vector>
using namespace std;

int countOfsubsetSum(vector<int>& arr, int n, int sumOfs1){
    vector<vector<int> > dp(n+1, vector<int>(sumOfs1+1));

    //initializing
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sumOfs1+1; j++){
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    //solving the small problems
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sumOfs1+1; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sumOfs1];
}

int main(){
    int n, diff;
    cout << "\nEnter the size of the array: ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "\nEnter the difference: ";
    cin >> diff;

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    int sumOfs1 = (diff + sum)/2;     //sumOfs1 => sum of subset s1
    int count = countOfsubsetSum(arr, n, sumOfs1);
    cout<<count<<endl;
    return 0;
}
