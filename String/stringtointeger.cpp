/*
Leetcode Question 8. String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/
*/

class Solution
{
public:
    // Time: O(N), Space: O(1)
    int myAtoi(string s)
    {
        if (s.size() == 0)
            return 0;

        int res = 0;
        int sign = 1;
        int idx = 0;

        // if the string will be full of whitespaces
        while (idx < s.size() && (s[idx] == ' '))
            idx++;

        // handle sign for digits
        if (idx < s.size() && (s[idx] == '+' || s[idx] == '-'))
        {
            sign = s[idx] == '+' ? 1 : -1;
            idx++;
        }
        int i = idx;
        while (i < s.size() && (s[i] >= '0' && s[i] <= '9'))
        {
            int digit = s[i] - '0';

            /*
            if the expected value will be == INT_MAX, then return sign*INT_MAX
            because that expected value could be a negative one
            */
            if (1LL * 10 * res + digit == INT_MAX)
            {
                return sign * INT_MAX;
            }

            /*
            if the expected value will be > INT_MAX, then we have to check sign
            because that value could be the negative so if the sign will be +ve
            then return INT_MAX, else return INT_MIN;
            */
            if (1LL * 10 * res + digit > INT_MAX)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = 10 * res + digit;
            i++;
        }
        return (res * sign);
    }
};
