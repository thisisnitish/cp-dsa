/*
Leetcode Question 993. Cousins in Binary Tree
https://leetcode.com/problems/cousins-in-binary-tree/
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
    /*the basic idea is find the height of the of tree till the value and
    simultaneously store the parent and repeat this process recursively.
    Time: O(N)*/
    int findHeight(TreeNode *curr, int &parent, int value, int height)
    {
        if (!curr)
            return 0;
        if (curr->val == value)
            return height;

        parent = curr->val;
        int left = findHeight(curr->left, parent, value, height + 1);
        if (left)
            return left;
        parent = curr->val;
        int right = findHeight(curr->right, parent, value, height + 1);
        return right;
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root->val == x || root->val == y)
            return false;

        int xParent = -1;
        int yParent = -1;

        int xHeight = findHeight(root, xParent, x, 0);
        int yHeight = findHeight(root, yParent, y, 0);
        /*if height are same and parents not return true*/
        if (xHeight == yHeight && xParent != yParent)
            return true;
        return false;
    }
};