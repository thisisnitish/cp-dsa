/*
Leetcode Question 103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    /*the basic idea is here we are using a stack and a variable 
    reverseLevel, when it is false then push the values normally
    into the vector and normally proceed with level order traversal
    approach but if reverseLevel is true then first push the values 
    in the stack and after at the end of the inner loop, continuously
    pop the values from the stack and push to the helper.
    Time: O(N), Space: O(N)*/
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        if (!root)
            return result;

        stack<int> s;
        queue<TreeNode *> q;
        q.push(root);
        bool reverseLevel = false;
        int status = 0;
        while (!q.empty())
        {

            int n = q.size();
            vector<int> helper;

            while (n--)
            {

                TreeNode *temp;
                temp = q.front();
                q.pop();

                if (reverseLevel)
                {
                    s.push(temp->val);
                }
                else
                {
                    helper.push_back(temp->val);
                }

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            if (reverseLevel)
            {
                while (!s.empty())
                {
                    helper.push_back(s.top());
                    s.pop();
                }
            }
            result.push_back(helper);
            reverseLevel = !reverseLevel;
        }
        return result;
    }
};