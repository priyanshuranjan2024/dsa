#include<bits/stdc++.h>
using namespace std;

//ques
//given a graph check whether there is a path between any 2 vertices or not
vector<list<int>> graph;

unordered_set<int> visited;//to keep a check on those nodes we have visited
vector<vector<int>> result;

int v;//no. of vertices

void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);

    }

}

//for any path funtion we will have to make a dfs funtion
void dfs(int curr,int end,vector<int>&path){
    //base case
    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        //now we also have to view other possibility
        path.pop_back();
        return;
    }
    //firstly mark it visited
    visited.insert(curr);
    path.push_back(curr);

    for(auto neighbours:graph[curr]){
        if(not visited.count(neighbours)){
            dfs(neighbours,end,path);
            
        }
    }

    path.pop_back();
    //erase the curr from visited
    visited.erase(curr);//since it can be a part of the other path
    return;

    


}

void allPath(int src,int dest){
    vector<int>v;


    dfs(src,dest,v);

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

    allPath(0,6);
    //after this we will have all path in the result vector 
    //so iterate over the result vector
    for(auto ele:result){
        for(auto el:ele) cout<<el<<" ";
        cout<<endl;

    }






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