/*
Leetcode Question 94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    /*this is the standard problem of traversal but the only 
    difference is, here we have to return all the elements in
    a vector. So, instead of printing the values just push them
    to the vector and return it. Time: O(N), Space: O(N)*/
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        helper(result, root);
        return result;
    }

    void helper(vector<int> &result, TreeNode *root)
    {
        if (!root)
            return;
        helper(result, root->left);
        result.push_back(root->val);
        helper(result, root->right);
    }
};

//Iterative
class Solution
{
public:
    /*this approach is same as the recursive, but here we are going
    deep to the left subtree, pushing nodes in stack simultaneously 
    then pop the ndoes from the stack and push to the result and go 
    for the right subtree. Time: O(N), Space: O(N)*/
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *temp = root;

        while (temp != NULL || !st.empty())
        {
            while (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            result.push_back(temp->val);
            temp = temp->right;
        }
        return result;
    }
};