/*
Leetcode Question 326. Power of Three
https://leetcode.com/problems/power-of-three/
*/

class Solution {
public:
    //Time: O(log3N), Space: O(1)
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        while(n%3 == 0){
            n = n/3;
        }
        return n == 1;
    }
};