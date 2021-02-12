/*
Brothers From Different Roots
https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1#
*/

/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
/*the basic idea is take an inorder traversal of the bst
and for every element in the first vector subtract that
from the x and take the resultant and find in the other
vector and if number is found then increase found value.
Time: O(N), Space: O(N)*/
void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int countPairs(Node *root1, Node *root2, int x)
{
    // Code here
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);

    int found = 0;
    for (auto ele : v1)
    {
        int complement = x - ele;
        if (find(v2.begin(), v2.end(), complement) != v2.end())
        {
            found++;
        }
    }
    return found;
}