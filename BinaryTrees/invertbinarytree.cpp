/*
Leetcode Question 226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/
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
//Solution 1
class Solution
{
public:
    /*the basic idea is to call for the left and right
    subtrees and swap the pointers. Time: O(N), Space: O(N)*/
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return NULL;

        TreeNode *right = root->right;

        root->right = invertTree(root->left);
        root->left = invertTree(right);

        return root;
    }
};

//Solution 2
class Solution
{
public:
    /*the basic idea is to call for the left and right
    subtrees and swap the pointers. Time: O(N), Space: O(N)*/
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return NULL;

        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        root->left = right;
        root->right = left;

        return root;
    }
};