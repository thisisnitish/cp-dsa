/*CPP Code for Bellman Ford algorithm
The basic idea is to relax the edges V-1 times to find the shortest path and
again relax every edges, if there exist the shortest path then it is sure that there
exist a negative cycle in the graph, otherwise display the shortest path
Time: O(V*E)
Input:
Enter the number of vertices: 5
Enter the number of edges: 8
Enter the sourceNode: 0

Enter the vertices(u, v) and their and edge weights:
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

Output:
Vertex          Ditance from Source
0               0
1               -1
2               2
3               -2
4               1
*/

#include<iostream>
#include<vector>
using namespace std;

//representation of an edge
struct Edge{
    int u, v, weight;
};

//representation of a graph
struct Graph{
    int V, E;    //V=>vertices, E=>edges
    struct Edge *edge; //graph is represented as an array of edges.
};

//function to create graph with V vertices and E edges
struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void displaySolution(vector<int>& distance, int V){
    cout<<"Vertex\t\tDitance from Source\n";
    for(int i=0; i<V; i++){
        cout<<i<<"\t\t"<<distance[i]<<endl;
    }
}

//function to find the shortest path from single source to all other vertices
void bellmanFord(struct Graph* graph, int sourceNode){
    int V = graph->V;
    int E = graph->E;
    //initialize distance from source to all other vertices as INT_MAX i.e INFINITE(in theory)
    vector<int> distance(V, INT_MAX);
    distance[sourceNode] = 0;      //distance from sourceNode to sourceNode is 0

    //this is the relaxation step executing V-1 times
    for(int i=0; i<=V-1; i++){
        for(int j=0; j<E; j++){
            int u = graph->edge[j].u;
            int v = graph->edge[j].v;
            int weight = graph->edge[j].weight;

            if(distance[u] != INT_MAX && distance[v] > distance[u] + weight){
                distance[v] = distance[u] + weight;
            }
        }
    }

    /*this is to find the negative-weight cycle. The above step
    guarantees shortest distances if graph doesn't contain
    negative weight cycle.  If we get a shorter path, then there
    is a cycle.*/

    for(int i=0; i<E; i++){
        int u = graph->edge[i].u;
        int v = graph->edge[i].v;
        int weight = graph->edge[i].weight;

        if(distance[u] != INT_MAX && distance[v] > distance[u] + weight){
           cout<<"\nGraph contains negative weight cycle";
           return;
        }
    }

    displaySolution(distance, V);
}


int main(){
    int V, E, sourceNode;
    cout<<"\nEnter the number of vertices: ";
    cin>>V;
    cout<<"\nEnter the number of edges: ";
    cin>>E;
    cout<<"\nEnter the sourceNode: ";
    cin>>sourceNode;

    struct Graph* graph = createGraph(V, E);


    cout<<"\nEnter the vertices(u, v) and their and edge weights:\n";
    int u, v, weight;
    for(int i=0; i<E; i++){
        cin>>u>>v>>weight;
        graph->edge[i].u = u;
        graph->edge[i].v = v;
        graph->edge[i].weight = weight;
    }

    bellmanFord(graph, sourceNode);
    return(0);
}
