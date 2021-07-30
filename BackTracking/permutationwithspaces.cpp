/*
Permutation with Spaces
https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1#
*/

class Solution
{
public:
    vector<string> result;
    void helper(string S, string op)
    {
        if (S.size() == 0)
        {
            result.push_back(op);
            return;
        }

        string op1 = op;
        string op2 = op;

        //two choices
        //with spaces
        op1.push_back(' ');
        op1.push_back(S[0]);

        //without spaces
        op2.push_back(S[0]);

        S.erase(S.begin() + 0);

        helper(S, op1);
        helper(S, op2);
    }
    vector<string> permutation(string S)
    {
        string op;
        op.push_back(S[0]);
        S.erase(S.begin() + 0);
        helper(S, op);
        return result;
    }
};
