/*
Leetcode Question 513. Find Bottom Left Tree Value
https://leetcode.com/problems/find-bottom-left-tree-value/
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
    /*the basic idea is to follow the level order traversal
    and observe it, basically the front value of the queue is
    the desired value, if you repeatedly do it. Previously i used
    stack just to store the left part of each subtree and at the end
    the desied node will be on top and return the top node value, but
    that was taking space, so I modified that solution to below one.
    Time: O(N), Space: O(N)*/
    int findBottomLeftValue(TreeNode *root)
    {

        int leftmost;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size(), i = 1;
            leftmost = q.front()->val;
            // cout<<leftmost<<" ";
            while (i <= n)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                    q.push(temp->right);
                i++;
            }
        }
        return leftmost;
    }
};