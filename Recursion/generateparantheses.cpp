/*
Leetcode Question 22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/
*/

class Solution
{
public:
    //Time: O(2^2n), Space: O(n)
    vector<string> parentheses;
    vector<string> generateParenthesis(int n)
    {
        int openBrackets = n;
        int closeBrackets = n;
        string output = "";
        helper(openBrackets, closeBrackets, output);
        return parentheses;
    }

    void helper(int openBrackets, int closeBrackets, string output)
    {
        //Base Condition
        if (openBrackets == 0 && closeBrackets == 0)
        {
            parentheses.push_back(output);
            return;
        }

        if (openBrackets != 0)
        {
            string output1 = output;
            output1.push_back('(');
            helper(openBrackets - 1, closeBrackets, output1);
        }
        if (closeBrackets > openBrackets)
        {
            string output2 = output;
            output2.push_back(')');
            helper(openBrackets, closeBrackets - 1, output2);
        }
    }
};