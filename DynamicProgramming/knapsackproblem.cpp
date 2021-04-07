/*CPP code for 0/1 Knapsack Problem
Given weights and values of n items, put these items in a knapsack of 
capacity W to get the maximum total value in the knapsack. You cannot
break an item because this is a 0/1 knapsack problem not the fractional one

Input:
Enter the number of weights and values you want: 3
Enter the capacity of the bag: 50
Enter the weights:
10 20 30
Enter the values:
60 100 120

Output:
Maximum Profit is: 220

Input:
Enter the number of weights and values you want: 4
Enter the capacity of the bag: 7
Enter the weights:
1 3 4 5
Enter the values:
2 4 5 7

Output:
Maximum Profit is: 9
*/

//Recursive implementation
//Time: O(2^n), Space: O(1)
#include<iostream>
using namespace std;

int knapsack(int values[], int weights[], int n, int W){
    if(n == 0 || W == 0)
        return 0;
    
    if(weights[n-1] <= W){
        return max(values[n-1] + knapsack(values, weights, n-1, W - weights[n-1]), knapsack(values, weights, n-1, W));
    }
    else //if(weights[n-1] > W)
        return knapsack(values, weights, n-1, W);
}

int main(){
    int n, W;
    cout<<"\nEnter the number of weights and values you want: ";
    cin>>n;
    int values[n], weights[n];
    cout<<"\nEnter the capacity of the bag: ";
    cin>>W;
    cout<<"\nEnter the weights:\n";
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }
    cout<<"\nEnter the values:\n";
    for(int i=0; i<n; i++){
        cin>>values[i];
    }

    int maxProfit = knapsack(values, weights, n, W);
    cout<<"Maximum Profit is: "<<maxProfit<<"\n";
    return(0);
}


//Memoization
//Time: O(N*W), Space: O(N*W)
#include<iostream>
#include<vector>
using namespace std;

int knapsackMemoization(vector<int>& values, vector<int>& weights, int n, int W, vector< vector<int> >& t){
    //base condition
    if(n == 0 || W == 0)
        return 0;

    //if the cell is not -1 then it has some value just return it
    if(t[n][W] != -1)
        return t[n][W];

    //if the weight is less than the capacity of bag then two choices, either include it or not
    if(weights[n-1] <= W)
        return t[n][W] = max(values[n-1] + knapsackMemoization(values, weights, n-1, W-weights[n-1], t), knapsackMemoization(values, weights, n-1, W, t));
    //if we don't want to include the element
    else //if(weights[n-1] > W)
        return t[n][W] = knapsackMemoization(values, weights, n-1, W, t);
}

int knapsack(vector<int>& values, vector<int>& weights, int n, int W){
    //creating the 2d array for memoization
    vector<vector<int> > t(n+1, vector<int>(W+1, -1));
    return knapsackMemoization(values, weights, n, W, t);
}

int main(){
    int n, W;
    cout << "\nEnter the number of weights and values you want: ";
    cin >> n;
    cout << "\nEnter the capacity of the bag: ";
    cin >> W;
    vector<int> values, weights;
    cout << "\nEnter the weights:\n";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        weights.push_back(x);
    }
    cout << "\nEnter the values:\n";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        values.push_back(x);
    }

    int maxProfit = knapsack(values, weights, n, W);
    cout<<"Maximum Profit is: "<<maxProfit<<"\n";
    return(0);
}

//Top-Down Approach
//Time: O(n*W), Space: O(n*W)
#include<iostream>
#include<vector>
using namespace std;


int knapsack(vector<int>& values, vector<int>& weights, int n, int W){
    vector<vector<int> > dp(n+1, vector<int> (W+1));

    //initializing the matrix
    for(int i=0; i<n+1; i++){
        for(int j=0; j<W+1; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    //filling the values of subproblem
    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(weights[i-1] <= j){
                dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    //returning the actual problem values
    return dp[n][W];
}

int main(){
    int n, W;
    cout << "\nEnter the number of weights and values you want: ";
    cin>>n;
    cout << "\nEnter the capacity of the bag: ";
    cin>>W;

    vector<int> values, weights;
    cout << "\nEnter the weights:\n";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        weights.push_back(x);
    }
    cout << "\nEnter the values:\n";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        values.push_back(x);
    }

    int maxProfit = knapsack(values, weights, n, W);
    cout << "Maximum Profit is: " << maxProfit << "\n";
    return (0);
}
