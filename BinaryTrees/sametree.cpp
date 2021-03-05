/*
Leetcode Question 100. Same Tree
https://leetcode.com/problems/same-tree/
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
    /*the basic idea is check every node for both trees parallely and
    call recursively for right and left subtrees. Time: O(N)*/
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
    }
};

//Solution 2 - using two queues
class Solution
{
public:
    /*here the basic idea is implement level order traversal
    and check every node, if they aren't same return false else
    continue with the loop. Time: O(N)
    */
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        // bool status = false;
        queue<TreeNode *> q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty())
        {
            TreeNode *temp1 = q1.front();
            TreeNode *temp2 = q2.front();
            q1.pop();
            q2.pop();

            if (temp1 == NULL && temp2 == NULL)
                continue;
            if (temp1 == NULL || temp2 == NULL)
                return false;
            if (temp1->val != temp2->val)
                return false;

            q1.push(temp1->left);
            q1.push(temp1->right);
            q2.push(temp2->left);
            q2.push(temp2->right);
        }
        return true;
    }
};

//Solution 3 - using one queue
class Solution
{
public:
    /*here the basic idea is implement level order traversal
    and check every node, if they aren't same return false else
    continue with the loop. Time: O(N)
    */
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        // bool status = false;
        queue<TreeNode *> Q;
        Q.push(p);
        Q.push(q);

        while (!Q.empty())
        {
            TreeNode *temp1 = Q.front();
            Q.pop();
            TreeNode *temp2 = Q.front();
            Q.pop();

            if (temp1 == NULL && temp2 == NULL)
                continue;
            if (temp1 == NULL || temp2 == NULL)
                return false;
            if (temp1->val != temp2->val)
                return false;

            Q.push(temp1->left);
            Q.push(temp2->left);
            Q.push(temp1->right);
            Q.push(temp2->right);
        }
        return true;
    }
};