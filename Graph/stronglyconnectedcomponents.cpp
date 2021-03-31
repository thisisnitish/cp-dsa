/*CPP code for checking a graph is strongly connected or not
The basic idea is to use Kosaraju algorithm using DFS

Following is Kosaraju’s DFS based simple algorithm that does two DFS traversals of graph:
1) Initialize all vertices as not visited.
2) Do a DFS traversal of graph starting from any arbitrary vertex v. 
If DFS traversal doesn’t visit all vertices, then return false.
3) Reverse all arcs (or find transpose or reverse of graph)
4) Mark all vertices as not-visited in reversed graph.
5) Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2). 
If DFS traversal doesn’t visit all vertices, then return false. Otherwise return true.

Time: O(V+E)

Input:
Enter the number of vertices: 5
Enter the number of edges: 6
0 1
1 2
2 3
3 0
2 4
4 2
Output:
Graph is Strongly Connected

Input:
Enter the number of vertices: 4
Enter the number of edges: 3
0 1
1 2
2 3
Output:
Graph is not Strongly Connected
*/

#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool isStronglyConnected();
    void DFSUtil(int v, vector<bool>& visited);
    Graph getTranspose();
};

//constructor
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

//destructor
Graph::~Graph(){
    delete[] adj;
}

//function to add the edge
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

//utility function to implement the DFS
void Graph::DFSUtil(int v, vector<bool>& visited){
    visited[v] = true;

    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
        if(!visited[*itr])
            DFSUtil(*itr, visited);
    }
}

//utility function to get the transpose of the graph
Graph Graph::getTranspose(){
    Graph newGraph(V);
    for(int v=0; v<V; v++){
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator itr;
        for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
            newGraph.adj[*itr].push_back(v);
        }
    }
    return newGraph;
}

//utility function to find the graph is strongly connected or not
bool Graph::isStronglyConnected(){

    //Step 1
    vector<bool> visited(V, false);

    //Step 2
    //we have taken a 0th vertex, you can take any vertex
    DFSUtil(0, visited);

    //check if any vertex is unvisited then return false
    for(int i=0; i<V; i++){
        if(visited[i] == false)
            return false;
    }

    //Step 3
    Graph graphTranspose = getTranspose();

    //Step 4
    for(int i=0; i<V; i++) visited[i] = false;

    //Step 5
    //Start vertex must be the same as starting of first of DFS
    graphTranspose.DFSUtil(0, visited);

    //if any vertex is not visited then return false
    for(int i=0; i<V; i++)
        if(visited[i] == false)
            return false;

    return true;
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
    graph.isStronglyConnected() ? cout<<"Graph is Strongly Connected\n" : cout<<"Graph is not Strongly Connected\n";

    return (0);
}
