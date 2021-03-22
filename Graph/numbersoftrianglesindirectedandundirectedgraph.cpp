/*CPP code for finding the Number of Triangles in directed and undirected graph
This program is for the adjacency matrix.
The basic idea is we have to check if there is an edge exist between i to j, j to k, and k to i
then it is sure that there exist a triangle. But for undirected graph there will be six combinations,
so to get the exact number of triangles for undirected graph we have to divide the total number of triangles 
by 6. On the contrary, for directed there will be only 3 combinations, so we will have to divide the total number 
of triangles by 3.
Input:
Enter the number of vertices
4

Consider the same graph as directed and undirected and give the inputs

Enter the adjacency matrix for undirected graph
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0

Enter the adjacency matrix for directed graph
0 0 1 0
1 0 0 1
0 1 0 0
0 0 1 0

Number of triangles in Undirected graph is: 2
Number of triangles in Directed graph is: 2
Time: O(N^3)
*/

#include<iostream>
#include<vector>
using namespace std;

int countTriangles(vector<vector<int> >& graph, bool isDirected, int V){
    int numberOfTriangles = 0;

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                if(graph[i][j] && graph[j][k] && graph[k][i]){
                    numberOfTriangles++;
                }
            }
        }
    }

    numberOfTriangles = isDirected ? numberOfTriangles/3 : numberOfTriangles/6;
    return(numberOfTriangles);
}

int main(){
    int V;
    cout<<"Enter the number of vertices\n";
    cin>>V;

    cout<<"\nConsider the same graph as directed and undirected and give the inputs\n";
    vector<vector<int> > undirectedGraph;
    vector<vector<int> > directedGraph;

    //input for undirected graph
    cout<<"\nEnter the adjacency matrix for undirected graph\n";
    for(int i=0; i<V; i++){
        vector<int> temp;
        for(int j=0; j<V; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        undirectedGraph.push_back(temp);
    }

    //input for directed graph
    cout<<"\nEnter the adjacency matrix for directed graph\n";
    for(int i=0; i<V; i++){
        vector<int> temp;
        for(int j=0; j<V; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        directedGraph.push_back(temp);
    }

    cout<<"\nNumber of triangles in Undirected graph is: ";
    int numberOfTrianglesForUndirectedGraph = countTriangles(undirectedGraph, false, V);
    cout<<numberOfTrianglesForUndirectedGraph;
    cout<<"\nNumber of triangles in Directed graph is: ";
    int numberOfTrianglesForDirectedGraph = countTriangles(directedGraph, true, V);
    cout<<numberOfTrianglesForDirectedGraph;

    return(0);
}
