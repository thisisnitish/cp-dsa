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
        //O(n)
        //compare the A till it is equal to the B and add character 
        //to the last and simultaneously delete from the front
        int i=alength;
        while(A != B){
            A += A[0];
            A.erase(A.begin());
            i--;
            if(i == 0) return 0;
        }
        return 1;

        //Solution 2
        //basically add the string A with A then find B as a substring
        A = A + A;
        if (A.find(B) != string::npos)
            return 1;
        return 0;
    }
};