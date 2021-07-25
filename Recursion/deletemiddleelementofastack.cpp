/*
Delete middle element of a stack
https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1#
*/

class Solution
{
public:
    //Function to delete middle element of a stack.
    //Time: O(N), Space: O(N)
    void helper(stack<int> &s, int k)
    {
        if (k == 1)
        {
            s.pop();
            return;
        }

        int val = s.top();
        s.pop();

        helper(s, k - 1);
        s.push(val);
    }
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        int k = (sizeOfStack / 2) + 1;
        helper(s, k);
    }
};
