/*
Leetcode Question 22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/
*/

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        int openBrackets = n;
        int closeBrackets = n;
        string output = "";
        helper(openBrackets, closeBrackets, output, result);
        return result;
    }

    void helper(int openBrackets, int closeBrackets, string output, vector<string> &result)
    {
        if (openBrackets == 0 and closeBrackets == 0)
        {
            result.push_back(output);
            return;
        }

        if (openBrackets != 0)
        {
            string op = output;
            op.push_back('(');
            helper(openBrackets - 1, closeBrackets, op, result);
        }

        if (closeBrackets > openBrackets)
        {
            string op = output;
            op.push_back(')');
            helper(openBrackets, closeBrackets - 1, op, result);
        }
    }
};
