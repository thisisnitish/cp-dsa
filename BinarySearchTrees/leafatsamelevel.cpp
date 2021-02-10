/*
Leaf at same level
https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#
*/

/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/*the basic idea is traverse every level and count for
left and right subtree and compare them. Time: O(N)
Space: O(h)*/
bool leaflevels(Node *root, int *level, int currentLevel)
{
    if (root == NULL)
        return true;

    /*if we encountered the leaf node*/
    if (root->left == NULL && root->right == NULL)
    {
        if (*level == 0)
        {
            *level = currentLevel;
            return true;
        }
        else
        {
            /*this is when we will be having the level value*/
            return (*level == currentLevel);
        }
    }

    return (leaflevels(root->left, level, currentLevel + 1) &&
            leaflevels(root->right, level, currentLevel + 1));
}
/*You are required to complete this method*/
bool check(Node *root)
{
    //Your code here
    int level = 0, currentLevel = 0;
    return leaflevels(root, &level, currentLevel);
}
