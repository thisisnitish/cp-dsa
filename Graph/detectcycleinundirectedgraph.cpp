/*CPP code for detecting the cycle in Undirected graph*/
/*
Time: O(V+E)
Space: O(V)
*/

//DFS
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
    bool isCyclicUtil(int v, vector<bool> &visited, int parent);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

/*A recursive function that uses visited[] and parent to detect
cycle in subgraph reachable from vertex v.*/
bool Graph::isCyclicUtil(int node, vector<bool> &visited, int parent){
    // Mark the current node as visited
    visited[node] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator itr;
    for(itr=adj[node].begin(); itr != adj[node].end(); itr++){
        if(!visited[*itr]){
            if(isCyclicUtil(*itr, visited, node)) return true;
        }
        else if(*itr != parent) return true;
    }
    return false;
}

bool Graph::isCyclic(){
    vector<bool> visited(V, false);

    for(int u=0; u<V; u++){
        if(!visited[u]){
            if(isCyclicUtil(u, visited, -1))
                return true;
        }
    }
    return false;
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

    if(graph.isCyclic()) cout<<"Graph contains cycle";
    else cout<<"Graph does not contains cycle";

    return 0;
}
