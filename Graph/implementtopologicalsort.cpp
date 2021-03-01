/*CPP code for topological sort*/
/*
Topological sorting for Directed Acyclic Graph (DAG) is a 
linear ordering of vertices such that for every directed edge u v, 
vertex u comes before v in the ordering. Topological Sorting for a 
graph is not possible if the graph is not a DAG
Time: O(V+E)
Space: O(V)
The algorithm is simply following the DFS with extra stack
*/

#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    //constructor
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack){
    //Mark the current node as visited
    visited[v] = true;

    //recur for all the vertices which are adjacent to v
    list<int>::iterator itr;
    for(itr=adj[v].begin(); itr!=adj[v].end(); itr++){
        if(!visited[*itr])
            topologicalSortUtil(*itr, visited, Stack);
    }
    //push the current node to the vertex for displaying the result
    Stack.push(v);
}

void Graph::topologicalSort(){
    vector<bool> visited(V, false);
    stack<int> Stack;

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            topologicalSortUtil(i, visited, Stack);
        }
    }

    //display the numbers
    cout<<"Topological Sort for the graph is: ";
    while(!Stack.empty()){
        cout<<Stack.top()<<" ";
        Stack.pop();
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

    graph.topologicalSort();
    return 0;
}
