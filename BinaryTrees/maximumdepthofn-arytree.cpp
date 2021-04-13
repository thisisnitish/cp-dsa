/*
Leetcode Question 559. Maximum Depth of N-ary Tree
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    int maxDepth(Node *root)
    {
        //base case
        if (!root)
            return 0;

        //check for all children and find the maximum depth
        int maxdepth = 0;
        vector<Node *>::iterator itr;
        for (itr = root->children.begin(); itr != root->children.end(); itr++)
        {
            maxdepth = max(maxdepth, maxDepth(*itr));
        }
        return maxdepth + 1;
    }
};