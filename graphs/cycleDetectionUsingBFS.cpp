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


bool bfs(int src){
    unordered_set<int> visited;
    queue<int> qu;
    vector<int> parent(v,-1);//this will store ith element parent

    visited.insert(src);
    qu.push(src);

    while(not qu.empty()){
        int curr=qu.front();
        qu.pop();
        //visit all its neighbours
        for(auto neighbour:graph[curr]){
            if(visited.count(neighbour) and parent[curr]!=neighbour) return true;//cycle detected
            if(not visited.count(neighbour)){
                visited.insert(neighbour);
                parent[neighbour]=curr;
                qu.push(neighbour);
            }
        }
    }

    return false;



    
   

}


bool hasCycle(){
    unordered_set<int> visited;
    bool result=false;
    for(int i=0;i<v;i++){
        if(not visited.count(i)){
            result=bfs(i);//since at start it will not have any neighbour
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

// 4 4
// 0 1
// 1 3
// 2 3
// 1 2