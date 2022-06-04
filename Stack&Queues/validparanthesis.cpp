/*
Leetcode Question 20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/
*/

//The basic idea plzz read the infix to postfix conversion application from stack
//then this question is a piece of cake for you

// I was able to solve this in 15 mins, 26 sec.
class Solution
{
public:
    // Time: O(N), Space: O(N)
    bool isValid(string s)
    {

        if (s.size() == 0)
            return true;
        if (s.size() == 1)
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
        return false;
    }
};
