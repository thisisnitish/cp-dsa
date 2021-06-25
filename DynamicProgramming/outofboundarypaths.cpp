/*
Leetcode Question 576. Out of Boundary Paths
https://leetcode.com/problems/out-of-boundary-paths/
*/

/*
the basic idea is to move every cell and go in all the 4 directions and check that we are 
going out of bounds or not, if we are going out of bounds then return 1 else 0. Also, keep 
track of number of moves, if moves are 0 the return 0 because we can't go anywhere if we 
don't have moves whatsoever.
*/
//Recrusive
class Solution
{
public:
    //Time: O(4^N), Space: O(N)
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        return helper(m, n, maxMove, startRow, startColumn) % mod;
    }

    int helper(int m, int n, int moves, int x, int y)
    {
        //if goes of out of bounds
        if (x >= m || y >= n || x < 0 || y < 0)
            return 1;

        //if the number of moves becomes 0
        if (!moves)
            return 0;

        //recursive call to all the 4 adjacent sides
        return (helper(m, n, moves - 1, x - 1, y) + helper(m, n, moves - 1, x + 1, y) + helper(m, n, moves - 1, x, y - 1) + helper(m, n, moves - 1, x, y + 1));
    }
};

//Recursive + Memoization
class Solution
{
public:
    //Time: O(m*n*maxMove), Space: O(m*n*maxMove)
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int> > > memo(maxMove + 1, vector<vector<int> >(m, vector<int>(n, -1)));
        return helper(m, n, maxMove, startRow, startColumn, memo);
    }

    int helper(int m, int n, int moves, int x, int y, vector<vector<vector<int> > > &memo)
    {
        //if goes of out of bounds
        if (x >= m || y >= n || x < 0 || y < 0)
            return 1;

        //if the number of moves becomes 0
        if (!moves)
            return 0;

        if (memo[moves][x][y] != -1)
            return memo[moves][x][y];

        vector<vector<int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int result = 0;

        for (auto d : dir)
        {
            result += helper(m, n, moves - 1, x + d[0], y + d[1], memo);
            result %= mod;
        }

        return memo[moves][x][y] = result % mod;
    }
};

//Memoization, using map
class Solution
{
public:
    int mod = 1e9 + 7;
    unordered_map<string, int> memo;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        return helper(m, n, maxMove, startRow, startColumn);
    }

    int helper(int m, int n, int moves, int x, int y)
    {
        //if goes of out of bounds
        if (x >= m || y >= n || x < 0 || y < 0)
            return 1;

        //if the number of moves becomes 0
        if (!moves)
            return 0;

        string key = to_string(x) + "-" + to_string(y) + "-" + to_string(moves);

        if (memo.find(key) != memo.end())
            return memo[key];

        vector<vector<int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int result = 0;
        for (auto d : dir)
        {
            result += helper(m, n, moves - 1, x + d[0], y + d[1]);
            result %= mod;
        }

        return memo[key] = result;
    }
};
