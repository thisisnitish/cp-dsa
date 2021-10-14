/*
Leetcode Question 124. Binary Tree Maximum Path Sum
https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    //Time: O(N)
    int maxPathSum(TreeNode *root)
    {
        int maxPath = INT_MIN;
        helper(root, maxPath);
        return maxPath;
    }

    int helper(TreeNode *root, int &maxPath)
    {
        if (!root)
            return 0;

        int left = helper(root->left, maxPath);
        int right = helper(root->right, maxPath);

        //find the maximum sum through the root node
        int temp = max(max(left, right) + root->val, root->val);

        //find the maximum sum through the path irrespective of the root node
        int ans = max(temp, left + right + root->val);

        //since we will be having the maximum sum stored in ans and now we only have to
        //compare with our final answer
        maxPath = max(maxPath, ans);
        return temp;
    }
};