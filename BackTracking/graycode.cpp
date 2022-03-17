/*
Leetcode Question 89. Gray Code
https://leetcode.com/problems/gray-code/
*/

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<string> temp = getGrayCode(n);
        vector<int> result;
        for (auto s : temp)
        {
            result.push_back(stoi(s, 0, 2));
        }
        return result;
    }

    vector<string> getGrayCode(int n)
    {
        if (n == 1)
            return {"0", "1"};

        // get the gray code of the previous number
        vector<string> previousNumberGrayCode = getGrayCode(n - 1);
        vector<string> currentNumberGrayCode;
        int size = previousNumberGrayCode.size();
        // add 0s in front to all the digits
        for (auto i : previousNumberGrayCode)
        {
            currentNumberGrayCode.push_back("0" + i);
        }

        // add 1s in front to all the digits but in reverse order
        for (int i = size - 1; i >= 0; i--)
        {
            currentNumberGrayCode.push_back("1" + previousNumberGrayCode[i]);
        }

        return currentNumberGrayCode;
    }
};