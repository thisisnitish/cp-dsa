/*
Leetcode Question 1690. Stone Game VII
https://leetcode.com/problems/stone-game-vii/
*/

//Recursive
class Solution
{
public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += stones[i];

        return helper(stones, 0, n - 1, sum);
    }

    int helper(vector<int> &stones, int front, int back, int sum)
    {
        if (front >= back)
            return 0;
        if (sum <= 0)
            return 0;

        //choosing the leftmost stone
        int chooseFront = sum - stones[front] - helper(stones, front + 1, back, sum - stones[front]);

        //choosing the rightmost stone
        int chooseBack = sum - stones[back] - helper(stones, front, back - 1, sum - stones[back]);
        return max(chooseFront, chooseBack);
    }
};

//Recrusive + Memoization
class Solution
{
public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += stones[i];

        vector<vector<int> > memo(n + 1, vector<int>(n + 1, -1));
        return helper(stones, 0, n - 1, sum, memo);
    }

    int helper(vector<int> &stones, int front, int back, int sum, vector<vector<int> > &memo)
    {
        if (front >= back)
            return 0;
        if (sum <= 0)
            return 0;

        if (memo[front][back] != -1)
            return memo[front][back];

        int chooseFront = sum - stones[front] - helper(stones, front + 1, back, sum - stones[front], memo);
        int chooseBack = sum - stones[back] - helper(stones, front, back - 1, sum - stones[back], memo);
        return memo[front][back] = max(chooseFront, chooseBack);
    }
};
