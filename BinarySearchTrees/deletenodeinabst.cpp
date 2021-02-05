/*
Leetcode Question 450. Delete Node in a BST
https://leetcode.com/problems/delete-node-in-a-bst/
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
    /*this is standard problem of deleting a node in BST.
    first we have to search the node that is going to be delete and
    then delete it. For deleting that we have to take care of 3 conditions
    such as, if that node have both the children, if that node have any one
    of the children either left or right, or if the node don't have any children.
    Time: O(h)*/
    TreeNode *findMin(TreeNode *root)
    {
        if (root->left == NULL)
            return root;
        return findMin(root->left);
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            /*this is the time when the node will be found and
            now only deletion part is left*/

            /*this is the case when node have both the children*/
            if (root->left && root->right)
            {
                TreeNode *temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, root->val);
            }
            else
            {

                /*this is the case when node have only one children
                either left or right or no children*/
                TreeNode *temp = root;
                if (root->left == NULL)
                    root = root->right;
                else if (root->right == NULL)
                    root = root->left;

                delete (temp);
            }
        }
        return root;
    }
};