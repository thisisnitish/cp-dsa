/*CPP code for unbounded knapsack problem
Basically, this is the another version of knapsack problem, we already know that in 0/1 knapsack
we have a choice for a particular thing i.e. whether we should take it or not. And in both the cases,
if we take the item and include in the bag that means that item is processed and it is not going to process
anymore similarly if we don't want to include that in the bag then also this case is processed.
But, in unbounded knapsack, if we will not include the item in the bag that means that item is processed same like 0/1
knapsack, but if we include the item in the bag then there is a change i will include another instances of that item
i.e. multiple occurences of an item.
we have done only bottom up approach, but it can be done in memoization and recursion also


Inpput: 
Enter the number of weights and values you want: 3
Enter the capacity of the bag: 100
Enter the weights:
5 10 15
Enter the values:
10 30 20

Output:
Maximum Profit is: 300*/

//Bottom Up
//Time: O(n*W), Space: O(n*W)
#include<iostream>
#include<vector>
using namespace std;

int unboundedKnapsack(vector<int>& values, vector<int>& weights, int n, int W){
    vector<vector<int> > dp(n+1, vector<int>(W+1));

    //initializing
    for(int i=0; i<n+1; i++){
        for(int j=0; j<W+1; j++){
            if(i == 0 || j == 0) 
                dp[i][j] = 0;
        }
    }

    //solving the small problems to find the bigger one
    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(weights[i-1] <= j)
                dp[i][j] = max(values[i-1] + dp[i][j-weights[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
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

    int maxProfit = unboundedKnapsack(values, weights, n, W);
    cout << "Maximum Profit is: " << maxProfit << "\n";
    return (0);
}
