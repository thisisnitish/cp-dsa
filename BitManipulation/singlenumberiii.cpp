/*
Leetcode Question 260. Single Number III
https://leetcode.com/problems/single-number-iii/
*/

class Solution
{
public:
    int getBit(int n, int pos)
    {
        return ((n & (1 << pos)) != 0);
    }

    vector<int> singleNumber(vector<int> &nums)
    {
        int xorsum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            xorsum = xorsum ^ nums[i];
        }

        int tempxor = xorsum;
        int pos = 0, setbit = 0;
        while (setbit != 1)
        {
            setbit = xorsum & 1;
            pos++;
            xorsum = xorsum >> 1; //getting the next bit
        }

        int newxor = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (getBit(nums[i], pos - 1))
            {
                newxor = newxor ^ nums[i];
            }
        }
        vector<int> result;
        result.push_back(newxor);
        result.push_back((tempxor ^ newxor));

        return result;
    }
};