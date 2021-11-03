/*
Leetcode Question 129. Sum Root to Leaf Numbers
https://leetcode.com/problems/sum-root-to-leaf-numbers/
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

/*
Basic idea is to explore all the paths and then store the digits that you encounter on the
way and then find the result. So, whenever there is an exploring all the path stuff then we
should think of recursion. And, since it is a tree related question then there is a high
chance of using recursion.

Now, we will do pre-order traversal for this tree and when we hit any node we will convert
that node val to string and concatenate to our string s and whenever we hit the leaf node we
will store the string s in a vector name paths.

Basically, paths is a vector which stores all the path from root-to-leaf in a string format.

Now, after that we will traverse the vector and convert all the strings to digits one by one
and add them and return the ans i.e. sum.
*/

// Solution 1
class Solution
{
public:
    // Time: O(N), Space: O(H)
    vector<string> paths;
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        findSumNumber(root, "");
        int sum = 0;
        for (auto path : paths)
        {
            int n = stoi(path);
            sum += n;
        }
        return sum;
    }

    void findSumNumber(TreeNode *root, string s)
    {
        if (!root)
            return;

        s += to_string(root->val);

        // if the node is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            paths.push_back(s);
            s.pop_back();
            return;
        }

        findSumNumber(root->left, s);
        findSumNumber(root->right, s);
        s.pop_back();
    }
};

/*
Now, the problem with above approach is, we are using extra vector for storing all the paths
So, we can do something to eliminate the vector.

Now, the idea is to replicate the above solution but we will have one variable name path
that will store the val from root-to-leaf in the form of number on the way.

When we hit the leaf node we will add that number i.e. path to our sum variable. Also, in
order to exlore all paths we will remove the last digit from path variable.
*/

// Solution 2
class Solution
{
public:
    // Time: O(N), Space: O(H)
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;

        int sum = 0;
        findSumNumber(root, 0, sum);
        return sum;
    }

    void findSumNumber(TreeNode *root, int path, int &sum)
    {
        if (!root)
            return;

        path = path * 10 + root->val;

        // if the node is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            sum += path;
            path = path / 10;
            return;
        }

        findSumNumber(root->left, path, sum);
        findSumNumber(root->right, path, sum);
        path = path / 10;
    }
};
