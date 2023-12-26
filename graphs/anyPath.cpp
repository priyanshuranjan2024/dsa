#include<bits/stdc++.h>
using namespace std;

//ques
//given a graph check whether there is a path between any 2 vertices or not
vector<list<int>> graph;
unordered_set<int> visited;//to keep a check on those nodes we have visited

int v;//no. of vertices

void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);

    }

}

//for any path funtion we will have to make a dfs funtion
bool dfs(int curr,int end){
    //base case
    if(curr==end) return true;
    //firstly mark it visited
    visited.insert(curr);
    for(auto neighbours:graph[curr]){
        if(not visited.count(neighbours)){
            bool res=dfs(neighbours,end);
            if(res) return true;
        }
    }

    return false;


}

bool anyPath(int src,int dest){

    return dfs(src,dest);

}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;

    visited.clear();
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    cout<<anyPath(0,6)<<endl;






    return 0;
}

// 7 8
// 0 1 
// 0 4 
// 4 3
// 3 1
// 1 5
// 5 6
// 6 2
// 5 2