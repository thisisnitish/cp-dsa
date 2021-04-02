/*CPP code for count the strongly connected components
The basic idea is to use Kosaraju's algorithm for finding the all SCCs
1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, 
after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. 
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. 
Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. 

Time: O(V+E)
Input:
Enter the number of vertices: 5
Enter the number of edges: 5
1 0
0 2
2 1
0 3
3 4

Output:
Strongly Connected Components are:
0 1 2 
3 
4 
*/

#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFSUtil(int v, vector<bool>& visited);
    void printStronglyConnectedComponent();
    void fillOrder(int v, vector<bool>& visited, stack<int>& Stack);
    Graph getTranspose();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, vector<bool>& visited){
    visited[v] = true;
    cout<<v<<" ";

    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
        if(!visited[*itr])
            DFSUtil(*itr, visited);
    }
}

Graph Graph::getTranspose(){
    Graph newGraph(V);
    for(int v=0; v<V; v++){

        list<int>::iterator itr;
        for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
            newGraph.adj[*itr].push_back(v);
        }
    }
    return newGraph;
}

void Graph::fillOrder(int v, vector<bool>& visited, stack<int>& Stack){
    visited[v] = true;

    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
        if(!visited[*itr])
            fillOrder(*itr, visited, Stack);
    }

    Stack.push(v);
}

void Graph::printStronglyConnectedComponent(){
    stack<int> Stack;

    vector<bool> visited(V, false);

    for(int i=0; i<V; i++){
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
    }

    Graph graphTranspose = getTranspose();

    for(int i=0; i<V; i++) visited[i] = false;

    while(!Stack.empty()){
        int v = Stack.top();
        Stack.pop();

        if(visited[v] == false){
            graphTranspose.DFSUtil(v, visited);
            cout<<endl;
        }
    }
}

int main(){
    int V, E;
    cout<<"\nEnter the number of vertices: ";
    cin>>V;
    cout<<"\nEnter the number of edges: ";
    cin>>E;

    Graph graph(V);
    int v, w;
    for(int i=0; i<E; i++){
        cin>>v>>w;
        graph.addEdge(v, w);
    }
    cout<<"\nStrongly Connected Components are:\n";
    graph.printStronglyConnectedComponent();
    return (0);
}
