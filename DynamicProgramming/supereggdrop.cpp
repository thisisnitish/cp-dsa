/*
Leetcode Question 887. Super Egg Drop
https://leetcode.com/problems/super-egg-drop/
*/

//This is a classic egg dropping problem
/*
The basic idea is, we have to find the minimum number of attempts to find the 
Threshold Floor, that means, above that floor the egg will break and below that 
floor the egg will not break

So, we have two choices
1. Egg will break
2. Egg will not break

-> For the first case if the egg will break from a particular floor then we have to go below
that floor
-> For the second case if the egg will not break from a particular floor then we have to go
above to find the threshold floor

Base Conditions:
1. It is given that egg the will not be 0 so no check for this in code
2. If the egg will be 1 i.e. k = 1, So we need at minimum n moves to determine what the value
    of floor is i.e n attempts.
3. If the n is 0 then no floor 0 attempt.
4. If the n is 1 then only 1 attempt.
*/
//Recursive
class Solution
{
public:
    //Time: O(n*(2^min(n,k))), Space: O(n)
    int helper(int k, int n)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;

        int mn = INT_MAX;

        for (int i = 1; i <= n; i++)
        {

            /*representing both the choices
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            int temp = 1 + max(helper(k - 1, i - 1), helper(k, n - i));

            mn = min(mn, temp); //minimum number of attempts
        }
        return mn;
    }

    int superEggDrop(int k, int n)
    {
        //k means number of eggs, n means number of floors
        return helper(k, n);
    }
};

//Recursive + Memoized TopDown
class Solution
{
public:
    //Time: O(n^2*k), Space: O(n*k)
    int helper(int k, int n, vector<vector<int> > &memo)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;

        if (memo[k][n] != -1)
            return memo[k][n];

        int mn = INT_MAX;

        for (int i = 1; i <= n; i++)
        {

            /*representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            int temp = 1 + max(helper(k - 1, i - 1, memo), helper(k, n - i, memo));

            mn = min(mn, temp); //minimum number of attempts
        }
        return memo[k][n] = mn;
    }

    int superEggDrop(int k, int n)
    {
        //k means number of eggs, n means number of floors
        vector<vector<int> > memo(k + 1, vector<int>(n + 1, -1));
        return helper(k, n, memo);
    }
};

//Optimized Memoization
class Solution
{
public:
    //Time: O(n^2*k), Space: O(n*k)
    int helper(int k, int n, vector<vector<int> > &memo)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;

        if (memo[k][n] != -1)
            return memo[k][n];

        int mn = INT_MAX;

        for (int i = 1; i <= n; i++)
        {

            /*here is the optimization goes on, the basic idea is before 
            any function call we are checking if any value from that function 
            call is present or not*/
            int left = 0, right = 0;
            if (memo[k - 1][i - 1] != -1)
                left = memo[k - 1][i - 1];
            else
            {
                left = helper(k - 1, i - 1, memo);
                memo[k - 1][i - 1] = left;
            }

            if (memo[k][n - i] != -1)
                right = memo[k][n - i];
            else
            {
                right = helper(k, n - i, memo);
                memo[k][n - i] = right;
            }

            int temp = 1 + max(left, right);

            mn = min(mn, temp); //minimum number of attempts
        }
        return memo[k][n] = mn;
    }

    int superEggDrop(int k, int n)
    {
        //k means number of eggs, n means number of floors
        vector<vector<int> > memo(k + 1, vector<int>(n + 1, -1));
        return helper(k, n, memo);
    }
};

//Memoization + Binary Search
class Solution
{
public:
    //Time: O(n*k*logn), Space: O(n*k)
    int helper(int k, int n, vector<vector<int> > &memo)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;

        if (memo[k][n] != -1)
            return memo[k][n];

        int mn = INT_MAX, low = 0, high = n, temp = 0;

        while (low <= high)
        {

            int mid = (low + high) / 2;

            /*representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/

            int left = helper(k - 1, mid - 1, memo);
            int right = helper(k, n - mid, memo);

            temp = 1 + max(left, right);

            //since we need more temp value in worst case, so need to go above
            if (left < right)
                low = mid + 1;
            else
                high = mid - 1; //move to the downward

            mn = min(mn, temp); //minimum number of attempts
        }
        return memo[k][n] = mn;
    }

    int superEggDrop(int k, int n)
    {
        //k means number of eggs, n means number of floors
        vector<vector<int> > memo(k + 1, vector<int>(n + 1, -1));
        return helper(k, n, memo);
    }
};
