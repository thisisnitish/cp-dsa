/*
Leetcode Question 404. Sum of Left Leaves
https://leetcode.com/problems/sum-of-left-leaves/
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

/*
The idea is to implement the post order traversal and check for left leaves and add it to
sum the variable.
*/
//Solution 1
class Solution
{
public:
    //Time: O(N), Space: O(1)
    int sum = 0;
    int sumOfLeftLeaves(TreeNode *root)
    {
        /*In this method we are using a flag isLeftLeave to check whether the leaf is a
        left leaf or not*/
        helper(root, false);
        return sum;
    }

    void helper(TreeNode *root, bool isLeftLeave)
    {
        if (root == NULL)
            return;

        helper(root->left, true);
        if (root->left == NULL && root->right == NULL && isLeftLeave)
        {
            sum += root->val;
        }
        helper(root->right, false);
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(N), Space: O(1)
    int sum = 0;
    int sumOfLeftLeaves(TreeNode *root)
    {
        /*This method is working slightly different from the above one, here we are using
        pointers to check whether the leaf is a left leaf or not, but we are checking
        for left leaf from one step above*/
        helper(root);
        return sum;
    }

    void helper(TreeNode *root)
    {
        if (root == NULL)
            return;

        helper(root->left);
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            sum += root->left->val;
        }
        helper(root->right);
    }
};
