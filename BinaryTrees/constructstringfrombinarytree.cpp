/*
Leetcode Question 606. Construct String from Binary Tree
https://leetcode.com/problems/construct-string-from-binary-tree/
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
    /*the basic idea is to follow the preorder traversal of a binary tree
    and just follow the question. Time: O(N), Space: O(N)*/
    string tree2str(TreeNode *t)
    {
        if (!t)
            return "";

        string s = to_string(t->val);

        if (t->left)
        {
            s += '(' + tree2str(t->left) + ')';
        }
        else if (t->right)
            s += "()";

        if (t->right)
        {
            s += '(' + tree2str(t->right) + ')';
        }
        return s;
    }
};