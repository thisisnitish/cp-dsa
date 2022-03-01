/*
Snippet for Disjoint set. Union by Rank and Path Compression
*/


vector<int> parent(100000);
vector<int> rank(100000);

void makeSet(){
    int n;
    for(int i=0;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(int node){
    if(node == parent[node]){
        return node;
    }
    //this is a path compression
    return parent[node] = findParent(parent[node]);
}

void union(int u, int v){
    u = findParent(u);
    v = findParent(v);


    //put u under v
    if(rank[u] < rank[v]){
        parent[u] = v; 
    }
    //put v under u
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else if(rank[u] == rank[v]){
        parent[v] = u;
        rank[u]++;
    }
}

void main(){
    makeSet();
    int m;
    cin>>m;
    
    while(m--){
        int u, v;
        cin>>u>>v;
        union(u, v);
    }

    //if 2 and 3 belongs to same component or not
    if(findParent(2) != findParent(3)){
        cout<<"Not in same component"<<endl;
    }
    else{
        cout<<"In same component"<<endl;
    }
}
