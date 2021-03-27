/*CPP code for Krushkal's Algorithms for Adjacency Matrix
here Infinity means INT_MAX but to represent numerically we have taken this as 9999.
The basic idea is sort all the edges in increasing order of their weight,
pick the smallest edge check if it is forming a cycle with the mst so far if yes discard it
else include it in the tree and repeat this v-1 times (edges)
Input:
9999, 2, 9999, 6, 9999,
2, 9999, 3, 8, 5,
9999, 3, 9999, 9999, 7,
6, 8, 9999, 9999, 9,
9999, 5, 7, 9, 9999

Output:
Edge 0: (0, 1) Cost: 2
Edge 1: (1, 2) Cost: 3
Edge 2: (1, 4) Cost: 5
Edge 3: (0, 3) Cost: 6
Minimum Cost: 16
This is not an efficient solution
*/

#include<iostream>
#include<vector>
using namespace std;

#define V 5
int parent[V];

int find(int i){
    while(parent[i] != i){
        i = parent[i];
    }
    return i;
}

void union1(int i, int j){
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void krushkals(int cost[][V]){
    int minCost = 0;
    // vector<int> parent(V, 0);
    for(int i=0; i<V; i++)
        parent[i] = i;

    int edgeCount = 0;
    while(edgeCount < V-1){
        int min = 9999, a = -1, b = -1;
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(find(i) != find(j) && cost[i][j] < min){
                    a = i;
                    b = j;
                    min = cost[i][j];
                }
            }
        }

        union1(a, b);
        cout<<"Edge "<<edgeCount++<<": ("<<a<<", "<<b<<") "<<"Cost: "<<min<<endl;
        minCost += min;
    }
    cout<<"Minimum Cost: "<<minCost<<endl;
}

int main(){
    // int V;
    // cout<<"Enter the number of vertices: ";
    // cin>>V;

    int cost[][V] = {
        { 9999, 2, 9999, 6, 9999 },
        { 2, 9999, 3, 8, 5 },
        { 9999, 3, 9999, 9999, 7 },
        { 6, 8, 9999, 9999, 9 },
        { 9999, 5, 7, 9, 9999 }
    };

    krushkals(cost);
    return(0);
}
