/*
Leetcode Question 1008. Construct Binary Search Tree from Preorder Traversal
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    /*the basic idea is first value of array will be the root because
    it is in preorder, then traverse the array and get the index till
    wehre the smaller value that root value exist and then pass that
    index for left subtree and rest for right subtree.
    Time: O(N), Space: O(N)*/
    TreeNode *createTree(vector<int> &preorder, int start, int end)
    {
        if (start > end)
            return NULL;

        /*first val of array is root val since it is preorder*/
        TreeNode *root = new TreeNode(preorder[start]);
        /*traverse through array and get the index where the root val
        becomes smaller*/
        int i;
        for (i = start; i <= end; i++)
        {
            if (preorder[i] > root->val)
                break;
        }

        root->left = createTree(preorder, start + 1, i - 1);
        root->right = createTree(preorder, i, end);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = createTree(preorder, 0, preorder.size() - 1);
        return root;
    }
};