/*CPP code for implementing the dijkstra algorithm using set in STL
This code is for undirected graph
STL provide the priority_queue, but the problem with this is it does not support
decrease key and delete operations. So, to overcome this problem we will use Set.
The operations are:
1. From all those vertices whose shortest distance not yet found, we need to 
get with the minimum distance.
2.  After extracting vertex we need to update distance of its adjacent vertices, 
and if new distance is smaller, then update that in data structure.

Input:
Enter the number of vertices: 9
Enter the number of edges: 14
Enter the source node: 0
Enter the vertices and their edge weights:
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

Output:
Vertex          Distance from Source: 
0               0
1               4
2               12
3               19
4               21
5               11
6               9
7               8
8               14
Time: O(E logV)
*/

#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;

class Graph{
    int V;
    list<pair<int, int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void dijkstra(int sourceNode);
    void displaySolution(vector<int>& distance);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<pair<int, int> >[V];
}

void Graph::displaySolution(vector<int>& distance){
    cout<<"Vertex\t\tDistance from Source: \n";
    for(int i=0; i<V; i++){
        cout<<i<<"\t\t"<<distance[i]<<"\n";
    }
}

/*this function is for undirected graph*/
void Graph::addEdge(int u, int v, int weight){
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void Graph::dijkstra(int sourceNode){

    /*creating a set to store the vertices that are being preprocessed*/
    /*Set => <distance, vertex>*/
    set<pair<int, int> > Set;

    /*create a vector for distance of all vertices and initialize 
    with maximum distance i.e. Infinity(In theory)*/
    vector<int> distance(V, INT_MAX);
    distance[sourceNode] = 0;        //distance from source node to source node is 0

    /*after the change the distance of a vertex, put that vertex in the set*/
    Set.insert(make_pair(0, sourceNode));

    /*loop till all the shortest path for the vertices are finalized and at last, set will empty*/
    while(!Set.empty()){

        /*the first vertex in set is the minimum distance vertex, extract it from set*/
        pair<int, int> temp = *(Set.begin());
        Set.erase(Set.begin());

        /*vertex label is stored in second of pair (it 
        has to be done this way to keep the vertices 
        sorted distance (distance must be first item 
        in pair)
        */
        int u = temp.second;

        /*iterating over all the adjacent vertices of a vertex*/
        list<pair<int, int> > :: iterator itr;
        for(itr = adj[u].begin(); itr != adj[u].end(); itr++){

            /*get the vertex and weight of current adjacent of u*/
            int v = (*itr).first;
            int weight = (*itr).second;
            
            /*if there is shorter path to v through u then update there*/
            if(distance[v] > distance[u] + weight){

                /* If distance of v is not INF then it must be in 
                our set, so removing it and inserting again 
                with updated less distance.   
                Note : We extract only those vertices from Set 
                for which distance is finalized. So for them,  
                we would never reach here.  
                */

                if(distance[v] != INT_MAX){
                    Set.erase(Set.find(make_pair(distance[v], v)));
                }

                /*updating the distance of v*/
                distance[v] = distance[u] + weight;
                Set.insert(make_pair(distance[v], v));
            }
        }
    }

    displaySolution(distance);
}

int main(){

    int V, E, sourceNode;
    cout<<"\nEnter the number of vertices: ";
    cin>>V;
    cout<<"\nEnter the number of edges: ";
    cin>>E;
    cout<<"\nEnter the source node: ";
    cin>>sourceNode;

    Graph graph(V);

    cout<<"\nEnter the vertices(u, v) and their edge weights:\n";
    int u, v, weight;
    for(int i=0; i<E; i++){
        cin>>u>>v>>weight;
        graph.addEdge(u, v, weight);
    }

    graph.dijkstra(sourceNode);
    return 0;
}
