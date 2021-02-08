/*
Leetcode Question 106. Construct Binary Tree from Inorder and Postorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    /*the basic idea is, if you see carefully postorder 
    array the last value is root value of the entire tree,
    and from inorder you search the value and find idx so, that
    the left part of that value will be part of left subtree and
    right part will be right subtree, and same goes to the rest of
    the numbers when you create a subtrees in left and right side.
    here were using map so that searching takes constant time.
    Time: O(N), Space: O(N)*/
    unordered_map<int, int> mp;
    TreeNode *buildTreeUtil(vector<int> &inorder, int iStart, int iEnd, vector<int> &postorder, int pStart, int pEnd)
    {

        if (iStart > iEnd || pStart > pEnd)
            return nullptr;

        /*here we are adding the value to the root*/
        TreeNode *root = new TreeNode(postorder[pEnd]);
        int idx = mp[postorder[pEnd]];

        root->left = buildTreeUtil(inorder, iStart, idx - 1, postorder, pStart, pStart + (idx - iStart - 1));

        root->right = buildTreeUtil(inorder, idx + 1, iEnd, postorder, pStart + (idx - iStart), pEnd - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0)
            return nullptr;

        int n = inorder.size();

        /*here we are filling the values of inorder 
        inorder to perform search*/
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return buildTreeUtil(inorder, 0, n - 1, postorder, 0, n - 1);
    }
};

//Solution 2
class Solution
{
public:
    /*this is simpler approach, the basic idea is postorder last value
    is the root node after that use inorder to find the index, in order to
    set the boundary, and recursively repeat this process, make sure you first
    right subtree and left subtree in this case other wise you run into overflow
    error. Time: O(N), Space: O(N)*/
    unordered_map<int, int> mp;
    TreeNode *buildTreeUtil(vector<int> &postorder, int start, int end, int &pIndex)
    {
        if (start > end)
            return NULL;

        TreeNode *root = new TreeNode(postorder[pIndex--]);

        /*search the current node index in inorder sequence to determine
        the boundary of the left and right subtree of the current node*/
        int index = mp[root->val];

        // recursively construct the right subtree
        root->right = buildTreeUtil(postorder, index + 1, end, pIndex);
        // recursively construct the left subtree
        root->left = buildTreeUtil(postorder, start, index - 1, pIndex);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0)
            return nullptr;

        int n = inorder.size();

        /*here we are filling the values of inorder 
        inorder to perform search*/
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        int pIndex = n - 1;
        return buildTreeUtil(postorder, 0, n - 1, pIndex);
    }
};