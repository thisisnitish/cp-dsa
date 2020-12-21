/*
Leetcode Question 796. Rotate String
https://leetcode.com/problems/rotate-string/
*/

class Solution
{
public:
    bool rotateString(string A, string B)
    {
        int alength = A.length();
        int blength = B.length();

        if (alength != blength)
            return false;
        if (alength == 0)
            return true;

        //Solution 1
        int i=alength;
        while(A != B){
            A += A[0];
            A.erase(A.begin());
            i--;
            if(i == 0) return 0;
        }
        return 1;

        //Solution 2
        A = A + A;
        if (A.find(B) != string::npos)
            return 1;
        return 0;
    }
};