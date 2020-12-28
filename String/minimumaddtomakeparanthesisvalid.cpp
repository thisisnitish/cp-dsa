/*
Leetcode Question 921. Minimum Add to Make Parentheses Valid
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
*/
//The idea is plzz learn the infix to postfix conversion application of stack then this question is piece of cake for you

class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        //with stack
        //O(n)
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
        //O(n)
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