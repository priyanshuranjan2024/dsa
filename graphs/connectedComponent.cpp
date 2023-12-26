#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;


void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);

}

void dfs(int src,unordered_set<int>&visited){
    visited.insert(src);
    for(auto neighbour:graph[src]) if(not visited.count(neighbour)) dfs(neighbour,visited);

}

int connectedComponent(){
    int result=0;
    unordered_set<int>visited;

    for(int i=0;i<v;i++){
        //go to every vertex
        //if we can initialise a dfs from their we will get a connected component
        if(not visited.count(i)){
            result++;
            dfs(i,visited);
        }

    }

    return result;
}


int main(){

    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);

    }

    cout<<connectedComponent()<<endl;


    return 0;
}

// 7 8 
// 0 1
// 0 3
// 3 4
// 1 4
// 1 3
// 2 5
// 5 6
// 2 6
// 2