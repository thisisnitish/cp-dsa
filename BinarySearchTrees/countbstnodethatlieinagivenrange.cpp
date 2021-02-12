/*
Count BST nodes that lie in a given range 
https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#
*/

/*
The structure of a BST node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

//Solution 1
/*the basic idea is to traverse the bst and get the 
inorder traversal in an array and traverse the array 
for the values which should lies in the given range. 
Time: O(N), Space: O(N)*/
    void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
int getCount(Node *root, int l, int h)
{
    // your code goes here
    vector<int> v;
    inorder(root, v);

    int numberOfNodes = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= l && v[i] <= h)
            numberOfNodes++;
    }
    return numberOfNodes;
}

//Solution 2
/*the basic idea is traverse through bst and check if the node
lies in the range if yes then count 
else recursively go for left and right subtree.
Time: O(h+k)*/
int getCount(Node *root, int l, int h)
{
    // your code goes here
    if (!root)
        return 0;

    //if the l and h points to the same node
    if (root->data == l && root->data == h)
        return 1;

    /*if the ccurrent node is in the range the count 
  it and go for the left and right children*/
    if (root->data <= h && root->data >= l)
    {
        return (1 + getCount(root->left, l, h) +
                getCount(root->right, l, h));
    }

    /*if current node is smaller than low then go for the right subtree*/
    else if (root->data < l)
        return getCount(root->right, l, h);
    /*else go for the left subtree*/
    else
        return getCount(root->left, l, h);
}
