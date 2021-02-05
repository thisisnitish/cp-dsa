/*
Leetcode Question 230. Kth Smallest Element in a BST
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    /*the basic idea is to traverse the tree in Inorder fashion,
    and push the values in result vector till it's size is <= k, 
    and return the k-1. Time: O(N), Space: O(N)*/
    vector<int> result;
    void inOrder(TreeNode *root, int k)
    {
        if (!root)
            return;
        inOrder(root->left, k);
        if (result.size() <= k)
            result.push_back(root->val);
        else
            return;
        inOrder(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inOrder(root, k);
        return result[k - 1];
    }
};