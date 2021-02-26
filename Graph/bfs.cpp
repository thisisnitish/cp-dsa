/*CPP code for Breadth First Search*/
/*
Time: O(V+E)
*/

//Iterative
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
    void BFS(int s, vector<bool> &visited);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s, vector<bool> &visited){

    list<int> queue;

    //mark the node as visited first and then push to the queue
    visited[s] = true;
    queue.push_back(s);

    list<int> ::iterator itr;

    while(!queue.empty()){

        /*pop from the queue and print the node*/
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();

        /* do for their adjacent nodes and if it is not visited then first visit*/
        for(itr=adj[s].begin(); itr!=adj[s].end(); itr++){
            if(!visited[*itr]){
                visited[*itr] = true;
                queue.push_back(*itr);
            }
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
    for (int j = 0; j < E; j++){
        cin >> v >> w;
        graph.addEdge(v, w);
    }

    vector<bool> visited(V, false);

    //call for every unvisited vertex
    for (int i = 0; i < V; i++){
        if (!visited[i])
            graph.BFS(i, visited);
    }
    return (0);
}

//Recrusive
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(vector<bool> &visited, list<int> &queue);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(vector<bool> &visited, list<int> &queue){

    if (queue.empty())
        return;

    int s = queue.front();
    queue.pop_front();
    cout << s << " ";

    list<int>::iterator itr;

    for (itr = adj[s].begin(); itr != adj[s].end(); itr++){
        if (!visited[*itr]){
            visited[*itr] = true;
            queue.push_back(*itr);
        }
    }
    BFS(visited, queue);
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
    list<int> queue;

    //call for every unvisited vertex
    for (int i = 0; i < V; i++){
        if (!visited[i]){
            /*in this case first visit the node and push to 
            the queue and call the recursive function*/
            visited[i] = true;
            queue.push_back(i);
            graph.BFS(visited, queue);
        }
    }
    return (0);
}
