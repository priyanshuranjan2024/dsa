#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;


void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);


}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->"<<" ";
        //traverse over the linked list
        for(auto el:graph[i]) cout<<el<<", ";//printing neighbour
        cout<<endl;

    }
}


bool dfs(int src,int parent,unordered_set<int> &visited){
    visited.insert(src);
    for(auto neighbour:graph[src]){
        if(visited.count(neighbour) and neighbour!=parent) return true;//cycle detected

        if(not visited.count(neighbour)){
            bool res=dfs(neighbour,parent,visited);
            if(res==true) return true;
        }
    }

    //if no cycle detected

    return false;

}


bool hasCycle(){
    unordered_set<int> visited;
    bool result=false;
    for(int i=0;i<v;i++){
        if(not visited.count(i)){
            result=dfs(i,-1,visited);//since at start it will not have any neighbour
            if(result==true) return true;
        }
    }

    return false;//no cycle detected

}





int main(){
    cin>>v;
    int e;
    graph.resize(v,list<int>());
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    display();
    cout<<endl;
    
    bool res=hasCycle();
    cout<<res<<endl;

    return 0;
}