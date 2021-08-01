/*
Leetcode Question 784. Letter Case Permutation
https://leetcode.com/problems/letter-case-permutation/
*/

class Solution
{
public:
    //Time: O(2^n), Space: O(n)
    vector<string> result;
    vector<string> letterCasePermutation(string s)
    {
        string ip = s;
        string op = "";
        helper(ip, op);
        return result;
    }

    void helper(string ip, string op)
    {
        if (ip.size() == 0)
        {
            result.push_back(op);
            return;
        }

        if (isalpha(ip[0]))
        {
            string op1 = op;
            string op2 = op;

            op1.push_back(toupper(ip[0]));
            op2.push_back(tolower(ip[0]));

            ip.erase(ip.begin() + 0);

            helper(ip, op1);
            helper(ip, op2);
        }
        else
        {
            string op1 = op;
            op1.push_back(ip[0]);

            ip.erase(ip.begin() + 0);
            helper(ip, op1);
        }
    }
};
