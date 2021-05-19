/*
Leetcode Question 113. Path Sum II
https://leetcode.com/problems/path-sum-ii/
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
    /*this is a simple preorder traversal and traverse every single path
    Time: O(N), Space: O(H)*/
    vector<vector<int> > result;
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        vector<int> path;
        helper(root, sum, 0, path);
        return result;
    }

    void helper(TreeNode *root, int sum, int pathsum, vector<int> &path)
    {
        if (!root)
            return;

        pathsum += root->val;
        path.push_back(root->val);

        //checking if the root is leaf node
        if (!root->left && !root->right)
        {

            //then check for sum
            if (pathsum == sum)
                result.push_back(path);
            path.pop_back();
            return;
        }

        helper(root->left, sum, pathsum, path);
        helper(root->right, sum, pathsum, path);
        path.pop_back();
    }
};
