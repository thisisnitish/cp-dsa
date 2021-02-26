/*CPP code for Depth First Search*/
/*
Time: O(V+E)
*/

//Iterative
#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

public:
    Graph(int V);  //Constructor
    void addEdge(int v, int w);
    void DFS(int source, vector<bool> &visited);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS(int s, vector<bool> &visited){

    // Create a stack for DFS
    stack<int> Stack;

    // Push the current source node.
    Stack.push(s);
    list<int> ::iterator itr;

    while(!Stack.empty()){
        // Pop a vertex from stack and print it
        s = Stack.top();
        Stack.pop();

        /*
        Stack may contain same vertex twice. So
        we need to print the popped item only
        if it is not visited.
        */
        if(!visited[s]){
            cout<<s<<" ";
            visited[s] = true;
        }

        /*Get all adjacent vertices of the popped vertex s
        If a adjacent has not been visited, then push it
        to the stack.*/
        for(itr = adj[s].begin(); itr != adj[s].end(); itr++){
            if(!visited[*itr]){
                Stack.push(*itr);
            }
        }
    }
}

int main(){

    int V, E, source;
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

    vector<bool> visited(V, false);

    //call for every unvisited vertex
    for(int i=0; i<V; i++){
        if(!visited[i])
            graph.DFS(i, visited);
    }
    return (0);
}

//Recursive
#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V); //Constructor
    void addEdge(int v, int w);
    void DFS(int source, vector<bool> &visited);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int s, vector<bool> &visited)
{
    visited[s] = true;
    cout<<s<<" ";

    list<int> ::iterator itr;
    for(itr = adj[s].begin(); itr != adj[s].end(); itr++){
        if(!visited[*itr]){
            DFS(*itr, visited);
        }
    }
}

int main()
{

    int V, E, source;
    cout << "\nEnter the number of vertices: ";
    cin >> V;
    cout << "\nEnter the number of edges: ";
    cin >> E;

    Graph graph(V);

    int v, w;
    for (int j = 0; j < E; j++)
    {
        cin >> v >> w;
        graph.addEdge(v, w);
    }

    vector<bool> visited(V, false);

    //call for every unvisited vertex
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            graph.DFS(i, visited);
    }
    return (0);
}
