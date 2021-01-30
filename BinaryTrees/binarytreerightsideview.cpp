/*
Leetcode Question 199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/
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
    /*the basic idea is follow the level order traversal
    and observe it, we are pushing those value to the result
    which will be at the end of inner while loop.
    Time: O(N), Space:O(N)*/
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
        {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node;
            int size = q.size();
            while (size--)
            {
                node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(node->val);
        }
        return result;
    }
};