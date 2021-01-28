/*
Leetcode Question 543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/
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
    /*the basic idea is to find the height of the subtrees
    from left and right and find diameter from left and right
    subtrees and at last return the maximum of them.
    Time: O(N)*/
    int diameterOfBinaryTree(TreeNode *root)
    {
        int height = 0;
        return diameter(root, height);
    }

    int diameter(TreeNode *root, int &height)
    {
        if (!root)
        {
            height = 0; //height
            return 0;   //diameter
        }

        int leftheight = 0, rightheight = 0;
        int leftdiameter = diameter(root->left, leftheight);
        int rightdiameter = diameter(root->right, rightheight);

        height = max(leftheight, rightheight) + 1;

        return max({leftdiameter, rightdiameter, leftheight + rightheight});
    }
};