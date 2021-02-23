/*CPP Program for Graph representation with adjacency list*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
    int V; //no. of vertices;

    // pointer to an array containing adjcency lists
    list<int> *adj;

public:
    Graph(int V); //constructor

    //function to add an edge to an graph
    void addEdge(int v, int w);
    //function to display the graph
    void displayGraph(int V);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::displayGraph(int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "\nAdjacency List representation of vertex: " << i;
        for (auto x : adj[i]){
            cout << "->" << x;
        }
        cout << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
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

    cout << "Graph is: " << endl;
    graph.displayGraph(V);

    return (0);
}