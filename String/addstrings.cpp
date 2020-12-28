/*
Leetcode Question 415. Add Strings
https://leetcode.com/problems/add-strings/
*/

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result = "";
        int len1 = num1.length() - 1;
        int len2 = num2.length() - 1;
        int carry = 0;

        while (len1 >= 0 || len2 >= 0)
        {
            //getting the actual value to add the string according to ascii table
            int x1 = len1 >= 0 ? num1[len1] - '0' : 0;
            int x2 = len2 >= 0 ? num2[len2] - '0' : 0;
            
            //first calculate the overall sum and then find the result and carry from it
            int sum = x1 + x2 + carry;
            carry = sum / 10; //to get the carry

            sum = sum % 10; //to get the actual last value
            string temp = to_string(sum);
            result += temp;
            len1--;
            len2--;
        }

        if (carry)
        {
            string temp = to_string(carry);
            result += temp;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};