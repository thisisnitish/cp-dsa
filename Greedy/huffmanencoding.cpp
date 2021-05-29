/*
Huffman Encoding 
https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1#
*/

struct Node{
    char data;
    int freq;
    Node *left, *right;
    
    Node(char data, int freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(Node* l, Node* r){
        return (l->freq > r->freq);
    }
};

class Solution
{
    void print(struct Node* root, string s, vector<string>& v){
        if(!root) return;
        if(root->data != '$')
            v.push_back(s);
        print(root->left, s+"0", v);
        print(root->right, s+"1", v);
    }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    Node *left, *right, *top;
		    
		    priority_queue<Node*, vector<Node*>, compare> pq;
		    
		    for(int i=0; i<N; i++){
		        pq.push(new Node(S[i], f[i]));
		    }
		    
		    while(pq.size() != 1){
		        left = pq.top();
		        pq.pop();
		        
		        right = pq.top();
		        pq.pop();
		        
		        top = new Node('$', left->freq + right->freq);
		        
		        top->left = left;
		        top->right = right;
		        
		        pq.push(top);
		    }
		    vector<string> v;
		    print(pq.top(), "", v);
		    return v;
		}
};
