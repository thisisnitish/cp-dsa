/*
Leetcode Question 236. Lowest Common Ancestor of a Binary Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    /*the basic idea is to go for each node and check if its 
    value is p or q, and then pass left and right subtree recursively.
    Time: O(N), Space: O(N)*/
    TreeNode *result = NULL;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        findLCA(root, p, q);
        return result;
    }

    int findLCA(TreeNode *currentNode, TreeNode *p, TreeNode *q)
    {
        if (currentNode == NULL)
            return false;

        /*if the root value is == p or q*/
        int mid = (currentNode == p || currentNode == q) ? 1 : 0;

        /*pass the left subtree, if it returns true that 
        means there is value in left subtre*/
        int left = findLCA(currentNode->left, p, q) ? 1 : 0;

        /*pass the right subtree, if it returns true that 
        means there is value in right subtre*/
        int right = findLCA(currentNode->right, p, q) ? 1 : 0;

        /*if any two nodes became true then we have found the LCA*/
        if (mid + left + right >= 2)
            result = currentNode;

        return (mid + left + right > 0);
    }
};

class Solution
{
public:
    //Time: O(N), Space: O(N)
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //If root doesn't exists
        if (!root)
            return NULL;

        //If root is itself one of the node
        if (root == p or root == q)
            return root;

        //calling for the left and right subtree and traverse the left and right of current subtree
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        //both the node exist under current subtree
        if (left and right)
            return root;

        //both the node doesn't exist under current subtree
        if (!left and !right)
            return NULL;

        //if one node is present in right of subtree
        if (!left)
            return right;
        //if one node is present in left of subtree
        return left;
    }
};
