/*CPP code for Dijkstra's Shortest Path Algorithms with Adjacency Matrix
This code is for the undirected graph we can use dijkstra's for directed graph also.
This is algorithm finds the shortest distance from the source to all vertices
Time: O(V^2), but if the implementation will be in adjacency list then it
will reduced to O(E logV).
Input:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

Output:
Enter the source node: 0
Vertex           Distance from source
0               0
1               4
2               12
3               19
4               21
5               11
6               9
7               8
8               14
*/

#include<iostream>
#include<vector>
using namespace std;

#define V 9   //number of vertices

/*A utility function to find the vertex with minimum distance value, from
the set of vertices not yet included in shortest path tree*/
int minDistance(vector<int>& distance, vector<bool>& visited){
    int min = INT_MAX, min_index;
    for(int v=0; v<V; v++){
        if(visited[v] == false && distance[v] <= min){
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}

/*A utility function to print the constructed distance array*/
void displaySolution(vector<int>& distance){
    cout<<"Vertex \t\t Distance from source\n";
    for(int i=0; i<V; i++){
        cout<<i<<"\t\t"<<distance[i]<<"\n";
    }
}

/*Function that implements Dijkstra's single source shortest path algorithm
for a graph represented using adjacency matrix representation*/
void dijkstra(vector<vector<int> > &graph, int sourceNode){
    
    /*distance will hold the shortest distance from source to vertex v*/
    vector<int> distance(V, INT_MAX);
    distance[sourceNode] = 0;    // distance from source node to source node is 0

    /*this one deal that which of the vertex is visited or not, 
    if false not visited, if true then visited*/
    vector<bool> visited(V, false);

    //shortest for all vertices
    for(int count = 0; count<V-1; count++){

        /*Pick the minimum distance vertex from the set of vertices i.e. visited not
        yet processed. u is always equal to sourceNode in the first iteration*/
        int u = minDistance(distance, visited);

        visited[u] = true;

        /*Update dist value of the adjacent vertices of the picked or chosen vertex.*/
        for(int v=0; v<V; v++){

            /*Update distance[v] only if is not in visited, there is an edge from
            u to v, and total weight of path from src to  v through u is
            smaller than current value of distance[v]*/
            if(!visited[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]){
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
    //display the construcuted path or distance array
    displaySolution(distance);
}

int main(){
    vector<vector<int> > graph;
    cout<<"Enter the adjacency matrix: \n";
    for(int i=0; i<V; i++){
        vector<int> temp;
        for(int j=0; j<V; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        graph.push_back(temp);
    }

    int sourceNode;
    cout<<"\nEnter the source node: ";
    cin>>sourceNode;
    
    dijkstra(graph, sourceNode);
    return(0);
}
