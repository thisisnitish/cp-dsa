/*
Leetcode Question 144. Binary Tree Preorder Traversal
https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    /*this is a basic standard problem, the only difference
    is, we have to return the values. Time: O(N), Space: O(N)*/
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        result.push_back(root->val);
        helper(root->left, result);
        helper(root->right, result);
    }
};

//Iterative
class Solution
{
public:
    /*this approach is pretty similar to the recursive one, but
    we are using stack here initialized with root. Execute the loop
    till stack is not empty and print the node value and push the 
    it's right child in to the stack. Time: O(N), Space: O(N)*/
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;

        TreeNode *temp = root;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            if (temp)
            {
                result.push_back(temp->val);
                if (temp->right)
                    st.push(temp->right);

                temp = temp->left;
            }
            /*if the current node is null, pop a node from 
            the stack set the current node to the popped node*/
            else
            {
                temp = st.top();
                st.pop();
            }
        }
        return result;
    }
};