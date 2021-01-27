/*
Leetcode Question 107. Binary Tree Level Order Traversal II
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    /*the basic idea is same as we did the standard level order
    traversal question on leetcode only the one thing we have to use
    the stack to store the values so at the end we will pop the values
    and get the desired result. Time: O(N), Space: O(N)*/
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        vector<vector<int> > result;

        if (root == NULL)
            return result;

        stack<vector<int> > st;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> helper;
            int s = q.size();

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

            st.push(helper);
            helper.clear();
        }

        /*pop the values and push it to the result*/
        while (!st.empty())
        {
            vector<int> dummy = st.top();
            result.push_back(dummy);
            st.pop();
        }

        return result;
    }
};

//Solution 2
class Solution
{
public:
    /*this solution is pretty simple go through the standard
    level order traversal question on leetcode and at the end
    just reverse the result vector. Time: O(N), Space: O(N)*/
    vector<vector<int> > levelOrderBottom(TreeNode *root)
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
        reverse(result.begin(), result.end());
        return result;
    }
};