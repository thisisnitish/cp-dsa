/*
Preorder to Postorder
https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1#
*/

// pre : given preorder if the tree
// size : size of the array
// print postorder traveresal of the tree
/*the basic idea is to create a binary search tree from
preorder traversal. Time: O(N), Space: O(N)*/
Node *constructTreeUtil(int pre[], int start, int end)
{
    if (start > end)
        return NULL;

    Node *root = newNode(pre[start]);

    /*traverse through the array untill you 
    finish the left subtree part, and then call recursively
    for left and right subtree*/
    int i;
    for (i = start; i <= end; i++)
    {
        if (pre[i] > root->data)
        {
            break;
        }
    }

    root->left = constructTreeUtil(pre, start + 1, i - 1);
    root->right = constructTreeUtil(pre, i, end);
    return root;
}

Node *constructTree(int pre[], int size)
{
    //code here
    return constructTreeUtil(pre, 0, size - 1);
}
