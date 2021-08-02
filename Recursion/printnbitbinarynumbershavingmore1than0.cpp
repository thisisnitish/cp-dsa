/*
Print N-bit binary numbers having more 1s than 0s
https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1#
*/

class Solution
{
public:
    //Time: O(2^n), Space: O(2^n)
    vector<string> result;
    vector<string> NBitBinary(int N)
    {
        string op = "";
        int ones = 0, zeros = 0;
        helper(ones, zeros, N, op);
        return result;
    }

    void helper(int ones, int zeros, int N, string op)
    {
        if (N == 0)
        {
            result.push_back(op);
            return;
        }

        /*
	    if(ones > zeros){
	        string op1 = op;
	        string op2 = op;
	        
	        op1.push_back('1');
	        op2.push_back('0');
	        helper(ones+1, zeros, N-1, op1);
	        helper(ones, zeros+1, N-1, op2);
	    }
	    else{
	        string op1 = op;
	        op1.push_back('1');
	        helper(ones+1, zeros, N-1, op1);
	    }
	    */
        //Refactoring the above code
        /*
	        Since we are getting 1s at every branch but for 0s we are getting when
	        we have 1s > 0s, in that way we have 2 choices, either to choose 1 or
	        0.
	    */
        string op1 = op;
        op1.push_back('1');
        helper(ones + 1, zeros, N - 1, op1);

        if (ones > zeros)
        {
            string op2 = op;
            op2.push_back('0');
            helper(ones, zeros + 1, N - 1, op2);
        }
    }
};
