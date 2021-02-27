/*CPP code for detecting the cycle in directed graph*/
/*
Time: O(V+E)
Space: O(V)

Algorithm using DFS:
1. Create the graph using the given number of edges and vertices.
2. Create a recursive function that initializes the current index or vertex, visited, and recursion stack.
3. Mark the current node as visited and also mark the index in recursion stack.
4. Find all the vertices which are not visited and are adjacent to the current node. 
    Recursively call the function for those vertices, If the recursive function returns true, return true.
5. If the adjacent vertices are already marked in the recursion stack then return true.
6. Create a wrapper class, that calls the recursive function for all the vertices and 
   if any function returns true return true. Else if for all vertices the function returns false return false.
*/

//DFS
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recursion_stack);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recursive_stack){
    if(!visited[v]){
        visited[v] = true;
        recursive_stack[v] = true;

        /*Recur for all the vertices adjacent to this vertex*/
        list<int> ::iterator itr;
        for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
            if(!visited[*itr] && isCyclicUtil(*itr, visited, recursive_stack)) return true;
            else if(recursive_stack[*itr]) return true;
        }
    }
    recursive_stack[v] = false;
    return false;
}

bool Graph::isCyclic(){
    vector<bool> visited(V, false);
    vector<bool> recursion_stack(V, false);

    for(int i=0; i<V; i++){
        if(isCyclicUtil(i, visited, recursion_stack))
            return true;
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
