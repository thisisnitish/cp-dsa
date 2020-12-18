/*
Leetcode Question 190. Reverse Bits
https://leetcode.com/problems/reverse-bits/
*/

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            ans = ans << 1;
            ans = ans | (n & 1);
            n = n >> 1;
        }

        return ans;
    }
};