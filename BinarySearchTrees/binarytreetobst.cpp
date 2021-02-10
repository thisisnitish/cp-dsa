/*
Binary Tree to BST 
https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#
*/

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/
// The given root is the root of the Binary Tree
// Return the root of the generated BST
/*the basic idea is use level order traversal for binary
tree and get the values in the vector and sort it, so we will
have sorted values i.e. inorder form of bst and now create the
bst. Time: O(NlogN), Space: O(N)*/
Node *createbst(vector<int> &v, int low, int high)
{
    if (low > high)
    {
        return NULL;
    }

    int mid = (low + high) / 2;
    Node *temp = new Node(v[mid]);
    temp->left = createbst(v, low, mid - 1);
    temp->right = createbst(v, mid + 1, high);
    return temp;
}

Node *binaryTreeToBST(Node *root)
{
    //Your code goes here
    vector<int> v;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        v.push_back(temp->data);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    sort(v.begin(), v.end());
    int low = 0;
    int high = v.size() - 1;
    Node *bst = createbst(v, low, high);
    return bst;
}