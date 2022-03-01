/*
Leetcode Question 338. Counting Bits
https://leetcode.com/problems/counting-bits/
*/

// Solution 1
class Solution
{
public:
    // Time: O(NlogN), Space: O(N)
    int countSetBits(int x)
    {
        int count = 0;
        while (x)
        {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n)
    {
        vector<int> bits;
        for (int i = 0; i <= n; i++)
        {
            bits.push_back(countSetBits(i));
        }
        return bits;
    }
};

/*
Above solution is fine but below solution works in O(N) time.
*/

// Solution 2
class Solution
{
public:
    // Time: O(N)
    vector<int> countBits(int n)
    {
        vector<int> bits(n + 1);
        bits[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            bits[i] = i % 2 + bits[i / 2];
        }
        return bits;
    }
};

/*
we can think about whether the number is even or odd. If the number is even, the
number of 1s is equal to number which is half of it.
For e.g., the number 8 has the same 1s as the number 4.
The number 10 has the same amount of 1 bits as number 5.
That is because number i is just left shift by 1 bit from number i / 2.
Therefore, they should have the same number of 1 bits.

If the numbers are odd, e.g. 1, 3, 5, 7.
The number of 1 bits is equal to the number (i - 1) plus 1.
For e.g., for number 3, the number of 1 bits equals to the number 2 plus 1.
For number 11, it equals to number 10 + 1.
*/

// Solution 3
class Solution
{
public:
    // Time: O(N)
    vector<int> countBits(int n)
    {
        vector<int> bits(n + 1);
        bits[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
                bits[i] = bits[i / 2];
            else
                bits[i] = bits[i - 1] + 1;
        }
        return bits;
    }
};
