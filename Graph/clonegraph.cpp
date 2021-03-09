/*
Leetcode Question 133. Clone Graph
https://leetcode.com/problems/clone-graph/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
public:
    /*the basic idea is to do the BFS of a graph and while visiting the node
    make a clone of it. If the node is already visited then it already has a
    clone node*/
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        /*map to keep track of all the nodes which have already been created
        i.e. <node, cloneNode>*/
        map<Node *, Node *> mp;
        queue<Node *> q;
        //enqueue the source node
        q.push(node);

        Node *cloneNode;

        //make a clone of a node
        cloneNode = new Node();
        cloneNode->val = node->val;

        //put the clone node in the map
        mp[node] = cloneNode;
        while (!q.empty())
        {
            Node *u = q.front();
            q.pop();

            vector<Node *> v = u->neighbors;
            int n = v.size();

            for (int i = 0; i < n; i++)
            {
                /*if there is no clone node then create a clone of a node
                and put that into the map*/
                if (mp[v[i]] == NULL)
                {
                    cloneNode = new Node();
                    cloneNode->val = v[i]->val;
                    mp[v[i]] = cloneNode;
                    q.push(v[i]);
                }
                //add these neighbours to clone the graph node
                mp[u]->neighbors.push_back(mp[v[i]]);
            }
        }
        //return the address of cloned node
        return mp[node];
    }
};