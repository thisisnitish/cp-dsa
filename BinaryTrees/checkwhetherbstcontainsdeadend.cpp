/*
Check whether BST contains Dead End 
https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#
*/

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
/*the basic idea is dead end means we have to check 
say for x value in bst, check x-1 and x+1 present or not, 
if it is then return true else return false, store the all 
nodes in a set with 0 also and store all the leaf nodes in 
another set and then check for every leaf nodes value x 
whether x+1 and x-1 present in the set or not. Time: O(N)*/
void storeNodes(Node *root, unordered_set<int> &leafNodes, unordered_set<int> &allNodes)
{
    if (root == NULL)
        return;

    allNodes.insert(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        leafNodes.insert(root->data);
        return;
    }

    storeNodes(root->left, leafNodes, allNodes);
    storeNodes(root->right, leafNodes, allNodes);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    if (root == NULL)
        return false;

    unordered_set<int> leafNodes, allNodes;

    //inserting 0 for node value 1
    allNodes.insert(0);

    storeNodes(root, leafNodes, allNodes);

    unordered_set<int>::iterator itr;

    for (itr = leafNodes.begin(); itr != leafNodes.end(); itr++)
    {
        if (allNodes.find(*itr + 1) != allNodes.end() &&
            allNodes.find(*itr - 1) != allNodes.end())
        {
            return true;
        }
    }
    return false;
}
