/*
Leetcode Question 101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree/
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
//Iterative
class Solution
{
public:
    /*the basic idea is we have to observe that how thing look 
    in mirror i.e. left becomes right and right becomes, similary
    here the approach is push the root to the queue check for 
    the values, if not equal then return false, if both are null
    continue with loop and if one is null and other not then also
    return false and after that push the left subtree, then 
    right subtree and right subtree and left subtree and 
    repeat this process, because the right subtree of each tree is a 
    mirror reflection of the left subtree of the other tree. 
    Time: O(N), Space: O(N)*/
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);

        while (!q.empty())
        {
            TreeNode *tree1 = q.front();
            q.pop();
            TreeNode *tree2 = q.front();
            q.pop();

            if (tree1 == NULL && tree2 == NULL)
                continue;
            if (tree1 == NULL || tree2 == NULL)
                return false;
            if (tree1->val != tree2->val)
                return false;

            q.push(tree1->left);
            q.push(tree2->right);
            q.push(tree1->right);
            q.push(tree2->left);
        }
        return true;
    }
};

//Recursive
class Solution
{
public:
    /*this approach is pretty similar to the above one but here
    we are checking reversely for every level whether the subtrees
    are symmetric or not. Time: O(N), Space: O(N)*/
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }

    int isMirror(TreeNode *tree1, TreeNode *tree2)
    {
        if (tree1 == NULL && tree2 == NULL)
            return true;
        if (tree1 == NULL || tree2 == NULL)
            return false;

        return ((tree1->val == tree2->val) && isMirror(tree1->left, tree2->right) &&
                isMirror(tree1->right, tree2->left));
    }
};