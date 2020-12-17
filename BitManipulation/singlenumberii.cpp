/*
Leetcode Question 137. Single Number II
https://leetcode.com/problems/single-number-ii/
*/

class Solution
{
public:
 
    int getBit(int n, int pos)
    {
        return ((n & (1 << pos)) != 0);
    }

    int setBit(int n, int pos)
    {
        return (n | (1 << pos));
    }

    int singleNumber(vector<int> &nums)
    {
        int result = 0;

        //traversing from 0 to 32 in order to cover all the bits
        // can also take 64 in place of 32
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            //traverse all the elements and checking the set bit at ith position in every element
            for (int j = 0; j < nums.size(); j++)
            {
                if (getBit(nums[j], i))
                {
                    sum++;
                }
            }

            if (sum % 3 != 0)
            {
                result = setBit(result, i);
            }
        }
        return result;
    }
};