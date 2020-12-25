/*
Leetcode Question 921. Minimum Add to Make Parentheses Valid
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
*/

class Solution
{
public:
    int minAddToMakeValid(string S)
    {

        //with stack
        stack<char> st;

        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '(')
            {
                st.push(S[i]);
            }
            else if (st.size() > 0 && st.top() == '(')
                st.pop();
            else
                st.push(S[i]);
        }

        return st.size();

        //without stack
        int result = 0, balance = 0;
        
        for(int i=0; i<S.length(); i++){
            balance += S[i] == '(' ? 1 : -1;
            
            if(balance == -1){
                result++;
                balance++;
            }
        }
      return(result + balance);
    }
};