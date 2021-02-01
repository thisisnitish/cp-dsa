/*
Leetcode Question 112. Path Sum
https://leetcode.com/problems/path-sum/
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
    /*the basic idea is to traverse every single path and
    check whether the path sum is equal to the sum or not.
    Time: O(N), Space: O(N)*/
    bool hasPathSum(TreeNode *root, int sum)
    {

        return FindPathSum(root, sum, 0);
    }

    bool FindPathSum(TreeNode *root, int sum, int pathsum)
    {
        if (!root)
            return false;

        //adding to the pathsum
        pathsum += root->val;

        /* this is will be true if the node will be the 
        leaf node, then compare it and return the result*/
        if (!root->left && !root->right)
        {
            return pathsum == sum;
        }

        /*traversing for left and right subtree*/
        return (
            FindPathSum(root->left, sum, pathsum) ||
            FindPathSum(root->right, sum, pathsum));
    }
};