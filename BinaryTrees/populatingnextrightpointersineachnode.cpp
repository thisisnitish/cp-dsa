/*
Leetcode Question 116. Populating Next Right Pointers in Each Node
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//Solution 1
class Solution
{
public:
    /*the basic idea is to do level order traversal of a binary tree
    and take one extra pointer previous to handle the node in such a way that it will
    always point to it's next node on right side in the same level
    Time: O(N), Space: O(N)*/
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> q;
        q.push(root);
        Node *previous = NULL;
        while (!q.empty())
        {
            int s = q.size();

            while (s--)
            {
                Node *temp = q.front();
                q.pop();

                /*previous contains the previous node which 
                is going to connect with temp or the node which is at right side at same level*/
                if (previous)
                    previous->next = temp;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);

                previous = temp;
            }
            previous = NULL;
        }
        return root;
    }
};

//Solution 2
class Solution
{
public:
    /*the basic idea is traverse each node recursively and connect
    left node to right, it would be better if you draw on the paper and observe it.
    Time: O(N)*/
    void joinLefttoRight(Node *Left, Node *Right)
    {
        if (Left == NULL)
            return;

        /*connecting the left to right*/
        Left->next = Right;
        joinLefttoRight(Left->left, Left->right);
        joinLefttoRight(Left->right, Right->left);
        joinLefttoRight(Right->left, Right->right);
    }

    Node *connect(Node *root)
    {
        if (!root)
            return root;

        joinLefttoRight(root->left, root->right);
        return root;
    }
};
