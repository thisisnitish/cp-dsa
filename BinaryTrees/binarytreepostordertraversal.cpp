/*
Leetcode Question 145. Binary Tree Postorder Traversal
https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Recursive
class Solution
{
public:
    /*this is an standard problem, you will find the explanation
    for this on geeksforgeeks, the only difference is instead of
    printing the values we are pushing those values into the vector.
    Time: O(N), Space: O(N)*/
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        helper(root->left, result);
        helper(root->right, result);
        result.push_back(root->val);
    }
};

//Iterative
class Solution
{
public:
    /*the approach is very much similart but here we are using
    two stacks, one is to keep node and other is to keep the vlaues.
    push the left and right child of root one by one and then pop,
    do it repeatedly. O(N), Space: O(N)*/
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;

        stack<TreeNode *> st;
        st.push(root);
        stack<int> util;
        /*we can use the stack of node type also and 
        later on extract the vlaues*/

        while (!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            util.push(temp->val);

            if (temp->left)
                st.push(temp->left);
            if (temp->right)
                st.push(temp->right);
        }

        while (!util.empty())
        {
            int values = util.top();
            util.pop();
            result.push_back(values);
        }

        return result;
    }
};