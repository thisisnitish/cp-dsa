/*
Evaluation of Postfix Expression
https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#
*


class Solution
{
public:
    // The main function that returns value of a given postfix expression
    /*this is the standard problem, so better you learn by yourself.
    Time: O(N)*/
int evaluatePostfix(string S)
{
    stack<int> Stack;

    for (int i = 0; i < S.size(); i++)
    {
        //if it encounters the digit then push it to the stack
        if (isdigit(S[i]))
        {
            Stack.push(S[i] - '0');
        }
        else
        {
            //if it encounters the operand then pop above two values
            //and apply operations on them and again push it to the stack
            int v1 = Stack.top();
            Stack.pop();
            int v2 = Stack.top();
            Stack.pop();

            switch (S[i])
            {
            case '+':
                Stack.push(v2 + v1);
                break;
            case '-':
                Stack.push(v2 - v1);
                break;
            case '*':
                Stack.push(v2 * v1);
                break;
            case '/':
                Stack.push(v2 / v1);
                break;
            }
        }
    }
    return Stack.top();
    }
};