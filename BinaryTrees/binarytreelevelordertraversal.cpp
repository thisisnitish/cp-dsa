/*
Leetcode Question 102. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    /*this question is slightly changed as comparison to
    the standard level order traversal, because here we have
    to return all levels in form of vector of vectors.
    the basic idea is same using a queue but we will keep
    track of size everytime for each level and push the level data
    in helper vector and when size is 0 then push that vector in 
    result vector. Refer to the standard problem once.
    Time: O(N), Space: O(N)*/
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > result;

        if (root == NULL)
            return result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int s = q.size();
            vector<int> helper;

            while (s--)
            {
                TreeNode *temp = q.front();
                helper.push_back(temp->val);
                q.pop();

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            result.push_back(helper);
            helper.clear();
        }
        return result;
    }
};