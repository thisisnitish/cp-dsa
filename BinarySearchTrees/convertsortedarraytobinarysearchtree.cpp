/*
Leetcode Question 108. Convert Sorted Array to Binary Search Tree
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    /*we have sorted array i.e. we have inorder traversal and its middle
    element is the root, and its left value is left subtree and right value
    is right subtree and and recursively call for this.
    Time: O(N), Space: O(N)*/
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        int low = 0;
        int high = nums.size() - 1;

        TreeNode *root = helper(nums, low, high);
        return root;
    }

    TreeNode *helper(vector<int> &nums, int low, int high)
    {
        if (low > high)
            return NULL;

        int mid = (low + high) / 2;

        TreeNode *temp = new TreeNode(nums[mid]);
        temp->left = helper(nums, low, mid - 1);
        temp->right = helper(nums, mid + 1, high);

        return temp;
    }
};