/*CPP code for Rod Cutting Problem
Given a rod of length n inches and an array of prices that contains prices of all pieces of 
size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
The basic idea is that, this question is completely same as the unbounded knapsack problem nothing new in this
only the scenario is changed. But the situation and crux is same. So, I've implemented the unbounded knapsack
Input: 
Enter the length of the rod: 8
Enter the length:
1 2 3 4 5 6 7 8
Enter the price:
1 5 8 9 10 17 17 20

Output:
Maximum Profit is: 22
*/

//Recursion - Memoization(Top Down)
//Time: O(2^n), Space: O(1)
#include<iostream>
#include<vector>
using namespace std;

int rodCuttinghelper(vector<int>& price, vector<int>& length, int n, int N, vector<vector<int> >& dp){
    if(n == 0 || N == 0)
        return 0;
    
    if(dp[n][N] != -1)
        return dp[n][N];
    
    if(length[n-1] <= N)
        return dp[n][N] = max(price[n-1] + rodCuttinghelper(price, length, n, N-length[n-1], dp), rodCuttinghelper(price, length, n-1, N, dp));
    
    else
        return dp[n][N] = rodCuttinghelper(price, length, n-1, N, dp);
}


int rodCutting(vector<int>& price, vector<int>& length, int n, int N){
    vector<vector<int> > dp(n+1, vector<int>(N+1, -1));
    return rodCuttinghelper(price, length, n, N, dp);
}

int main(){
    int n, N;
    cout << "\nEnter the length of the rod: ";
    cin >> n;
    // cout << "\nEnter the capacity of the bag: ";
    // cin >> N;
    N = n; 

    vector<int> price, length;
    cout << "\nEnter the length:\n";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        length.push_back(x);
    }
    cout << "\nEnter the price:\n";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        price.push_back(x);
    }

    int maxProfit = rodCutting(price, length, n, N);
    cout << "Maximum Profit is: " << maxProfit << "\n";
    return 0;
}


//Bottom Up Approach
//Time: O(n*N), Space: O(n*N)
#include<iostream>
#include<vector>
using namespace std;

int rodCutting(vector<int>& price, vector<int>& length, int n, int N){
    vector<vector<int> > dp(n+1, vector<int>(N+1));

    //initializing
    for(int i=0; i<n+1; i++){
        for(int j=0; j<N+1; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    //solving the problems
    for(int i=1; i<n+1; i++){
        for(int j=1; j<N+1; j++){
            if(length[i-1] <= j)
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][N];
}

int main(){
    int n, N;
    cout << "\nEnter the length of the rod: ";
    cin >> n;
    // cout << "\nEnter the capacity of the bag: ";
    // cin >> N;
    N = n;

    vector<int> price, length;
    cout << "\nEnter the length:\n";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        length.push_back(x);
    }
    cout << "\nEnter the price:\n";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        price.push_back(x);
    }

    int maxProfit = rodCutting(price, length, n, N);
    cout << "Maximum Profit is: " << maxProfit << "\n";
    return 0;
}
