/*
Leetcode Question 617. Merge Two Binary Trees
https://leetcode.com/problems/merge-two-binary-trees/
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
    /*the basic idea is to traverse the tree and when both nodes exist, 
    add them and create a node, if one doesn't exist return the other one
    call for left and right subtree recursively, here we have to reutrn a new
    tree which will be the merged of the both the tree. Time: O(N), Space: O(N)*/
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {

        if (!root1)
            return root2;
        if (!root2)
            return root1;

        TreeNode *mergedTree = new TreeNode(root1->val + root2->val);
        mergedTree->left = mergeTrees(root1->left, root2->left);
        mergedTree->right = mergeTrees(root1->right, root2->right);

        return mergedTree;
    }
};