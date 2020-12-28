/*
Leetcode Question 20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/
*/

//The basic idea plzz read the infix to postfix conversion application from stack
//then this question is a piece of cake for you

class Solution
{
public:
    //O(n)
    bool isValid(string s)
    {

        if (s.length() == 0)
            return true;
        if (s.length() == 1)
            return false;

        stack<char> st;

        for (auto c : s)
        {
            if (c == ')' || c == ']' || c == '}')
            {
                if (st.empty())
                    return false;
                if (st.top() != '(' && c == ')')
                    return false;
                if (st.top() != '{' && c == '}')
                    return false;
                if (st.top() != '[' && c == ']')
                    return false;
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        if (st.empty())
            return true;
        else
        {
            return false;
        }
    }
};