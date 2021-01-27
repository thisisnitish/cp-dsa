/*
Leetcode Question 104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
//Solution 1
class Solution
{
public:
    /*the basic idea is to do the level order traversal
    and after finishing every level increase the height.
    Time: O(N), Space: O(1)*/
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int height = 0;
        while (!q.empty())
        {
            int s = q.size();

            while (s--)
            {
                TreeNode *temp = q.front();
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

            height++;
        }

        return height;
    }
};

//Solution 2
class Solution
{
public:
    /*the basic idea is to go deep for the left and right
    subtree and find the longest path. Time: O(N)*/
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);

            /*get the maximum one*/
            if (leftDepth > rightDepth)
                return leftDepth + 1;
            return rightDepth + 1;
        }
    }
};
