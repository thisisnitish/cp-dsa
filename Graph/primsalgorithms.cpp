/*CPP code for the prims algorithms. This program is for the adjacency matrix representation
of a graph. Basically MST are the subgraph of a graph containing all the vertices and V-1 edges.
In laymen terms, Prim's works in such a way that pick any vertex to start the algorithm and after
that choose the next vertex which is connected to it and contains the minimum edges weight.
Basically, prim's is trying to maintain the tree from the beginning of the algorithm
For, more formal algorithm, read GFG article on Prim's algorithm

Input:
Enter the number of vertices: 5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Output:
Edge            Weight
0 - 1           2
1 - 2           3
0 - 3           6
1 - 4           5

Time: O(V^2)
*/

#include<iostream>
#include<vector>
using namespace std;

/*A utility function to find the vertex with minimum key value, from the set of vertices
not yet included in MST*/
int minKey(vector<int>& key, vector<bool>& mstSet, int V){
    int min = INT_MAX, minIdx;
    for(int v = 0; v < V; v++){
        if(mstSet[v] == false && key[v] < min){
            min = key[v]; minIdx = v;
        }
    }
    return minIdx;
}

//utility function to print the MST stored in parent[]
void display(vector<int>& parent, vector<vector<int> >& graph, int V){
    cout<<"\nEdge\t\tWeight\n";
    for(int i=1; i<V; i++){
        cout<<parent[i]<<" - "<<i<<"\t\t"<<graph[i][parent[i]]<<"\n";
    }
}

/*function to construct MST*/
void prims(vector<vector<int> >& graph, int V){

    //key stores the minimum weight edge
    vector<int> key(V, INT_MAX);

    //mstSet includes the vertices included in MST
    vector<bool> mstSet(V, false);

    //stores the constructed MST
    vector<int> parent(V);

    //we are taking 0 as the source, but we can take any source
    key[0] = 0;
    parent[0] = -1;        //there is no parent of 0 i.e. first node is always the root node

    //the MST have V vertices
    for(int count = 0; count < V-1; count++){

        /*pick the minimum ket vertex from the set of vertices not yet included in MST*/
        int u = minKey(key, mstSet, V);
        
        //add the picked vertex to MST
        mstSet[u] = true;

        /*Update key value and parent index of the adjacent vertices of the picked vertex.
        Consider only those vertices which are not yet included in MST*/
        for(int v = 0; v < V; v++){

            /*graph[u][v] is non zero only for adjacent vertices of m
            mstSet[v] is false for vertices not yet included in MST
            Update the key only if graph[u][v] is smaller than key[v]*/
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    display(parent, graph, V);
}

int main(){
    int V;
    cout<<"\nEnter the number of vertices: ";
    cin>>V;

    vector<vector<int> > graph;

    for(int i=0; i<V; i++){
        vector<int> temp;
        for(int j=0; j<V; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        graph.push_back(temp);
    }

    prims(graph, V);
}
