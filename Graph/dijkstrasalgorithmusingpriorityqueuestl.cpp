/*Dijkstra’s Shortest Path Algorithm using priority_queue of STL
This code is for undirected graph
we have implemented this algorithm using set which in turns uses self-balancing binary search trees.
But for dijkstra's algorithm it is highly recommended to use priority_queue, so we are going to use this

However, the problem is, priority_queue doesn’t support decrease key. To resolve this problem, do not 
update a key, but insert one more copy of it. So we allow multiple instances of same vertex in priority 
queue. This approach doesn’t require decrease key operation and has below important properties.

Whenever distance of a vertex is reduced, we add one more instance of vertex in priority_queue. Even 
if there are multiple instances, we only consider the instance with minimum distance and ignore other instances.

Time: O(E log V)*/

#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<pair<int, int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void dijkstra(int sourceNode);
    void displaySolution(vector<int> &distance);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<pair<int, int> >[V];
}

void Graph::displaySolution(vector<int> &distance){
    cout << "Vertex\t\tDistance from Source: \n";
    for (int i = 0; i < V; i++){
        cout << i << "\t\t" << distance[i] << "\n";
    }
}

/*this function is for undirected graph*/
void Graph::addEdge(int u, int v, int weight){
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void Graph::dijkstra(int sourceNode){

    /*Create a priority queue to store vertices that are being preprocessed.*/
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    /*create a vector for distance of all vertices and initialize 
    with maximum distance i.e. Infinity(In theory)*/
    vector<int> distance(V, INT_MAX);
    distance[sourceNode] = 0;                  //distance from source node to source node is 0

    /*after the change the distance of a vertex, put that vertex in the queue*/
    pq.push(make_pair(0, sourceNode));

    /*loop till priority queue will empty*/
    while(!pq.empty()){

        /*The first vertex in pair is the minimum distance
        vertex, extract it from priority queue.
        vertex label is stored in second of pair (it
        has to be done this way to keep the vertices
        sorted distance (distance must be first item
        in pair)*/
        int u = pq.top().second;
        pq.pop();

        /*iterating over all the adjacent vertices of a vertex*/
        list<pair<int, int> > ::iterator itr;
        for(itr = adj[u].begin(); itr != adj[u].end(); itr++){

            /*get the vertex label and weight of current adjacent to u*/
            int v = (*itr).first;
            int weight = (*itr).second;

            /*if there is shorter path to v through u then update it*/
            if(distance[v] > distance[u] + weight){

                // Updating distance of v
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    displaySolution(distance);
}

int main(){

    int V, E, sourceNode;
    cout << "\nEnter the number of vertices: ";
    cin >> V;
    cout << "\nEnter the number of edges: ";
    cin >> E;
    cout << "\nEnter the source node: ";
    cin >> sourceNode;

    Graph graph(V);

    cout << "\nEnter the vertices(u, v) and their edge weights:\n";
    int u, v, weight;
    for (int i = 0; i < E; i++){
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    graph.dijkstra(sourceNode);
    return 0;
}
