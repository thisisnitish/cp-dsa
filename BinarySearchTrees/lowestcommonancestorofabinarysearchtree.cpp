/*
Leetcode Question 235. Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
//Solution 1
class Solution
{
public:
    /*i would highly recommend you to check the Lowest Common Ancestor of Binary Tree,
    if you have done that then this question is easy for you, you can directly paste the
    code but here we can take the advantage of the tree i.e. it is a bst, so we will go
    either left side or right side of the tree according to the p and q value.
    Time: O(N), Space: O(N)*/
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        /*if both p and q are greater than the node than check right subtree*/
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        /*if both p and q are lesser than the node than check left subtree*/
        else if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            /*this is the case where we have found the LCA*/
            return root;
        }
    }
};

//Solution 2
class Solution
{
public:
    /*the basic idea is similar to recursive approach but we 
    are doing in iterative way. Time: O(N), Space: O(1)*/
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *temp = root;

        while (temp)
        {
            if (p->val < temp->val && q->val < temp->val)
            {
                temp = temp->left;
            }
            else if (p->val > temp->val && q->val > temp->val)
            {
                temp = temp->right;
            }
            else
            {
                return temp;
            }
        }
        return NULL;
    }
};
