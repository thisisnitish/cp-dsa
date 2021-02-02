/*
Leetcode Question 114. Flatten Binary Tree to Linked List
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    /*the basic idea is perform preorder traversal and
    push the all values into the vector and then create a 
    new linked list from same TreeNode class.
    Time: O(N), Space: O(N)*/
    vector<int> v;
    void preorder(TreeNode *root)
    {
        if (!root)
            return;
        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    TreeNode *createLL(TreeNode *root)
    {
        if (v.size() == 0)
            return NULL;
        TreeNode *linkedList = new TreeNode();
        TreeNode *temp = linkedList;
        for (int i = 0; i < v.size(); i++)
        {
            temp->left = NULL;
            temp->right = new TreeNode(v[i]);
            temp = temp->right;
        }
        return linkedList->right;
    }

    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        preorder(root);
        TreeNode *temp = createLL(root);

        /*here root->right because it will have the value 1
        so if we write only temp then there will be two same values*/
        root->right = temp->right;
        root->left = NULL;
    }
};