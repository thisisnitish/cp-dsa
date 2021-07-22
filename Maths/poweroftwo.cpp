/*
Leetcode Question 231. Power of Two
https://leetcode.com/problems/power-of-two/
*/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {

        if (n <= 0)
            return 0;
        return (n & (n - 1)) ? false : true;
        //return (n && !(n & n-1));   //first n is for the corner case when n is 0
    }
};