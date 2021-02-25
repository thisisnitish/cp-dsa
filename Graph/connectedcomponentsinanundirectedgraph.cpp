/*
Given an undirected graph, print all connected components line by line.

Finding connected components for an undirected graph is an easier task. 
We simple need to do either BFS or DFS starting from every unvisited vertex, 
and we get all strongly connected components.

1) Initialize all vertices as not visited.
2) Do following for every vertex 'v'.
       (a) If 'v' is not visited before, call DFSUtil(v)
       (b) Print new line character

DFSUtil(v)
1) Mark 'v' as visited.
2) Print 'v'
3) Do following for every adjacent 'u' of 'v'.
    If 'u' is not visited, then recursively call DFSUtil(u)

Time: O(V+E)
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    ~Graph();
    void DFSUtil(int v, vector<bool> &visited);
    void addEdge(int v, int w);
    void connectedComponents();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph(){
    delete[] adj;
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v, vector<bool> &visited){
    visited[v] = true;
    cout<<v<<" ";

    list<int>::iterator itr;
    for(itr=adj[v].begin(); itr!=adj[v].end(); itr++){
        if(!visited[*itr]){
            DFSUtil(*itr, visited);
        }
    }
}

void Graph::connectedComponents(){
    vector<bool> visited(V, false);

    for(int v=0; v<V; v++){
        if(!visited[v]){
            DFSUtil(v, visited);
            cout<<"\n";
        }
    }
}

int main(){
    int V, E;
    cout << "\nEnter the number of vertices: ";
    cin >> V;
    cout << "\nEnter the number of edges: ";
    cin >> E;

    Graph graph(V);

    int v, w;
    for (int j = 0; j < E; j++){
        cin >> v >> w;
        graph.addEdge(v, w);
    }

    cout<<"Connected Components are: \n";
    graph.connectedComponents();
    return(0);
}
