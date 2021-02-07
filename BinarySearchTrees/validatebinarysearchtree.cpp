/*
Leetcode Question 98. Validate Binary Search Tree
https://leetcode.com/problems/validate-binary-search-tree/
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
    /*the basic idea is to traverse the tree and go to the node once,
    keeping track of each node and check that each node's val is more than 
    min value and less than max value. Time: O(N), Space: O(h)*/
    bool isValidBST(TreeNode *root)
    {

        /*initial values of min = LONG_MIN, max = LONG_MAX*/
        return utilBST(root, LONG_MIN, LONG_MAX);
    }

    int utilBST(TreeNode *root, long min, long max)
    {

        //this is also a valid bst
        if (!root)
            return 1;

        /*if this happens then binary tree is not a valid bst*/
        if (root->val <= min || root->val >= max)
            return 0;

        return utilBST(root->left, min, root->val) &&
               utilBST(root->right, root->val, max);
    }
};