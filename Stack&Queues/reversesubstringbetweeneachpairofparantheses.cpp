/*
Leetcode Question 1190. Reverse Substrings Between Each Pair of Parentheses
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
*/

class Solution
{
public:
    /*the basic idea is use stack and when you get '(' push the index of it
    and when you get ')' pop the corresponding top value from stack and reverse
    the string between those indexes and do this repeatedly. Time: O(N^2) Space: O(N)*/
    string reverseParentheses(string s)
    {
        stack<int> Stack;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                Stack.push(i);
            else if (s[i] == ')')
            {
                reverse(s.begin() + Stack.top(), s.begin() + i);
                Stack.pop();
            }
        }

        string result = "";
        for (auto i : s)
        {
            if (i != '(' && i != ')')
            {
                result += i;
            }
        }
        return result;
    }
};