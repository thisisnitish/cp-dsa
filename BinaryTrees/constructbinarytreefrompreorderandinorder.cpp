/*
Leetcode Question 105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    /*if you have done binary tree from postorder and inorder traversal then
    this question will be easy for you, because it id done with the similar way
    here the root value will be the first value of preorder and use map to store
    inorder values as key and i as value inorder to perfom search operation that will
    take constant time. Now manipulate the idx to create left and right subtrees.
    Please dry run this you will get insight. Time: O(N), Space: O(N)*/
    unordered_map<int, int> mp;
    TreeNode *buildTreeUtil(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd)
    {

        if (iStart > iEnd || pStart > pEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[pStart]);
        int idx = mp[preorder[pStart]];

        root->left = buildTreeUtil(preorder, pStart + 1, pStart + (idx - iStart) + 1, inorder, iStart, idx - 1);

        root->right = buildTreeUtil(preorder, pStart + (idx - iStart) + 1, pEnd, inorder, idx + 1, iEnd);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.size() == 0)
            return nullptr;

        int n = inorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return buildTreeUtil(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};