/*
Leetcode Question 688. Knight Probability in Chessboard
https://leetcode.com/problems/knight-probability-in-chessboard/
*/

/*
The idea is, we have a knight and it has to move in 8 directions and it has k moves in 
total. Also, in question it is given that, it will continue moving until k becomes 0 or
knight moves off the chessboard. And, we need to find the probabilitiy that knight remains
on the board after it has stopped moving.

Now, If you look at the problem, it generally talks about the path and exploration and stuff
like that. Whenever, we talk related to exploring all the path then we should think about
resursion.

Now, we have decided that we are going to use recursion and we will be exploring all the
paths. So, possible path for the knight is going to be given below,
when the knight is at (x, y) from there it will move,
(x + 2, y + 1)
(x + 1, y + 2)
(x – 1, y + 2)
(x – 2, y + 1)
(x – 2, y – 1)
(x – 1, y – 2)
(x + 1, y – 2)
(x + 2, y – 1)
in these many directions.

Now, let's talk about the probability, Since knight has to move in 8 directions, for one 
move of knight the probability will be 1/8.

Also, let's talk about the base case:
1. Check if the position is valid or not if not return 0.
2. Check if k == 0 or not, if k is 0 then there is no movement from knight and Probability
of knight on the borad is 1.
*/

//Recursive
class Solution
{
public:
    //Time: O(8^N)
    double knightProbability(int N, int K, int r, int c)
    {
        return helper(N, K, r, c);
    }

    double helper(int N, int K, int row, int col)
    {

        if (row < 0 || col < 0 || row >= N || col >= N)
            return 0.0;

        if (K == 0)
            return 1.0;

        double ans = helper(N, K - 1, row + 2, col + 1) + helper(N, K - 1, row + 1, col + 2) +
                     helper(N, K - 1, row - 1, col + 2) + helper(N, K - 1, row - 2, col + 1) +
                     helper(N, K - 1, row - 2, col - 1) + helper(N, K - 1, row - 1, col - 2) +
                     helper(N, K - 1, row + 1, col - 2) + helper(N, K - 1, row + 2, col - 1);

        double result = ans / 8.0;
        return result;
    }
};

//Recursive + Memoization
class Solution
{
public:
    //Time: O(N*N*K), Space: O(N*N*K)
    double knightProbability(int N, int K, int r, int c)
    {
        vector<vector<vector<double> > > memo(N + 1, vector<vector<double> >(N + 1, vector<double>(K + 1, -1)));
        return helper(N, K, r, c, memo);
    }

    double helper(int N, int K, int row, int col, vector<vector<vector<double> > > &memo)
    {

        if (row < 0 || col < 0 || row >= N || col >= N)
            return 0.0;

        if (K == 0)
            return 1.0;

        if (memo[row][col][K] != -1)
            return memo[row][col][K];

        double ans =
            helper(N, K - 1, row + 2, col + 1, memo) + helper(N, K - 1, row + 1, col + 2, memo) +
            helper(N, K - 1, row - 1, col + 2, memo) + helper(N, K - 1, row - 2, col + 1, memo) +
            helper(N, K - 1, row - 2, col - 1, memo) + helper(N, K - 1, row - 1, col - 2, memo) +
            helper(N, K - 1, row + 1, col - 2, memo) + helper(N, K - 1, row + 2, col - 1, memo);

        double result = ans / 8.0;
        memo[row][col][K] = result;
        return result;
    }
};

//Recursive + Memoization using map
class Solution
{
public:
    unordered_map<string, double> mp;
    double knightProbability(int N, int K, int r, int c)
    {
        mp.clear();
        return helper(N, K, r, c);
    }

    double helper(int N, int K, int row, int col)
    {

        if (row < 0 || col < 0 || row >= N || col >= N)
            return 0.0;

        if (K == 0)
            return 1.0;

        string key = to_string(K) + "#" + to_string(row) + "#" + to_string(col);
        if (mp.find(key) != mp.end())
            return mp[key];

        double ans = helper(N, K - 1, row + 2, col + 1) + helper(N, K - 1, row + 1, col + 2) +
                     helper(N, K - 1, row - 1, col + 2) + helper(N, K - 1, row - 2, col + 1) +
                     helper(N, K - 1, row - 2, col - 1) + helper(N, K - 1, row - 1, col - 2) +
                     helper(N, K - 1, row + 1, col - 2) + helper(N, K - 1, row + 2, col - 1);

        double result = ans / 8.0;
        mp[key] = result;
        return result;
    }
};
