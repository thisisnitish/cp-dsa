
/*
Link: https://atcoder.jp/contests/dp/tasks/dp_a
Recursive: O(2^N) or approx = Fib(N) or exponential or O(1.6^N)
Recursive + Memoization: O(N)
Iterative: O(N)
*/

//Recursive + Memoization
#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int solve(int N, vector<int>& heights){
    if(N == 0) return dp[N] = 0;
    if(N == 1) return dp[N] = abs(heights[1] - heights[0]);

    if(dp[N] != -1) return dp[N];
    int firstJump = solve(N-1, heights) + abs(heights[N] - heights[N-1]);
    int secondJump = solve(N-2, heights) + abs(heights[N] - heights[N-2]);

    return dp[N] = min(firstJump, secondJump);
}

int main(){
    int N;
    cin>>N;
    dp.resize(N, -1);
    vector<int> heights(N);
    for(int i=0; i <N; i++){
        cin>>heights[i];
    }

    cout<<solve(N-1, heights)<<endl;
    return 0;
}

//Iterative - Bottom Up
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N, -1);
    vector<int> heights(N);
    for (int i = 0; i < N; i++){
        cin >> heights[i];
    }

    dp[0] = 0; 
    dp[1] = abs(heights[1] - heights[0]);

    for(int i=2; i<N; i++){
        int firstJump = dp[i-1] + abs(heights[i] - heights[i-1]);
        int secondJump = dp[i-2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(firstJump, secondJump);
    }
    cout <<dp[N-1]<<endl;
    return 0;
}

//We can do quicker as well as compare to the iterative approach
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }

    int previousToPrevious = 0;
    int previous = abs(heights[1] - heights[0]);

    for (int i = 2; i < N; i++)
    {
        int firstJump = previous + abs(heights[i] - heights[i - 1]);
        int secondJump = previousToPrevious + abs(heights[i] - heights[i - 2]);

        previousToPrevious = previous;
        previous =  min(firstJump, secondJump);
    }
    cout << previous << endl;
    return 0;
}
