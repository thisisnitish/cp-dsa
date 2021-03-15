/*CPP code for Floyd Warshall Algorithm
this is basically the all pair shortest path i.e. shortest path between every pair of vertices
The idea is to one by one pick all vertices and updates all shortest paths which include the 
picked vertex as an intermediate vertex in the shortest path.
For every pair (i, j) of the source and destination vertices respectively, there are two possible cases. 
1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as 
dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
Time: O(V^3)
Put INF as 9999
Input:
Enter the number of vertices: 4
0 5 9999 10
9999 0 3 9999
9999 9999 0 1
9999 9999 9999 0

Output:
0       5       INF     10
INF     0       3       INF
INF     INF     0       1
INF     INF     INF     0
Todo: There is a bug in this code later on refactor it
*/

#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int> >& distance, int V){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(distance[i][j] == 9999) cout<<"INF"<<"\t";
            else cout<<distance[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void floydWarshall(vector<vector<int> >& graph, int V){

    /* distance will be the output matrix that will finally have the shortest 
    distances between every pair of vertices and for the sake of simplicity we have initialized with 0 */
    vector<vector<int> > distance(V, vector<int> (V, 0));

    /* Initialize the solution matrix same as input graph matrix. Or we can say 
    the initial values of shortest distances are based on shortest paths considering 
    no intermediate vertex. */
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            distance[i][j] = graph[i][j];
        }
    }

    /* Add all vertices one by one to the set of intermediate vertices. 
    ---> Before start of an iteration, we have shortest distances between all 
    pairs of vertices such that the shortest distances consider only the 
    vertices in set {0, 1, 2, .. k-1} as intermediate vertices. 
    ----> After the end of an iteration, vertex no. k is added to the set of 
    intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for(int k=0; k<V; k++){
        // Pick all vertices as source one by one
        for(int i=0; i<V; i++){
            // Pick all vertices as destination for the above picked source 
            for(int j=0; j<V; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of distance[i][j]
                if(distance[i][j] > distance[i][k] + distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    //display the solution matrix
    display(graph, V);
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



    floydWarshall(graph, V);

    return(0);
}
