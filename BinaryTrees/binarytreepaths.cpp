/*
Leetcode Question 257. Binary Tree Paths
https://leetcode.com/problems/binary-tree-paths/
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
The idea is simple, traverse the tree and when you reach the leaf node push the path into the
resultant vector.
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        string curr = "";
        helper(root, result, curr);
        return result;
    }

    void helper(TreeNode *root, vector<string> &result, string curr)
    {
        if (!root)
            return; //base case

        curr += to_string(root->val);

        //if the node is a leaf node then we are done with that path, we can just push that
        //path into result vector;
        if (!root->left && !root->right)
            result.push_back(curr);

        //recursion call for left and right subtree
        helper(root->left, result, curr + "->");
        helper(root->right, result, curr + "->");
    }
};
