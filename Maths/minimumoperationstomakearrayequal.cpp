/*
Leetcode Question 1551. Minimum Operations to Make Array Equal
https://leetcode.com/problems/minimum-operations-to-make-array-equal/
*/

//Detailed explaination is given here
// https://leetcode.com/problems/minimum-operations-to-make-array-equal/discuss/1148440/C%2B%2B-Math-Solution-Explained-Step-by-step-100-Time-~70-Space
class Solution
{
public:
    int minOperations(int n)
    {
        return n * n / 4;
    }
};