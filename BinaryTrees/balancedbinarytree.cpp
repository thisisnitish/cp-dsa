/*
Leetcode Question 110. Balanced Binary Tree
https://leetcode.com/problems/balanced-binary-tree/
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
class Solution
{
public:
    /*the basic idea is to check the left subtree is balanced,
    right subtree is balanced and the difference between heights 
    of left and right subtree is <= 1. Time: O(N)*/
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return 1;

        int lh = getheight(root->left);
        int rh = getheight(root->right);

        return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }

    int getheight(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = getheight(root->left);
        int rh = getheight(root->right);

        return (1 + max(lh, rh));
    }
};