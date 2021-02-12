/*
Leetcode Question 938. Range Sum of BST
https://leetcode.com/problems/range-sum-of-bst/
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
    /*the basic idea is take a inorder traversal and store the values in
    vector, find the low and high index and start the loop and add all those
    values within this range. Time: O(N), Space: O(N)*/
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        vector<int> v;
        inorder(root, v);

        auto lowIt = find(v.begin(), v.end(), low);
        int lowIdx = lowIt - v.begin();

        auto highIt = find(v.begin(), v.end(), high);
        int highIdx = highIt - v.begin();

        int sum = 0;
        for (int i = lowIdx; i <= highIdx; i++)
        {
            sum += v[i];
        }
        return sum;
    }
};