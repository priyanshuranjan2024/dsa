#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);

}

void topologicalSortBFS(){
    //Kahns algorithm
    //make an indegree vector
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto neighbour:graph[i]) indegree[neighbour]++;//since i->neighbour

    }

    queue<int> qu;//for multisource bfs
    unordered_set<int> visited;
    for(int i=0;i<v;i++){
        //check if ith element has indegree 0 if yes then push
        if(indegree[i]==0){
            qu.push(i);
            visited.insert(i);
        }
    }

    //now apply mulitisource bfs
    while(not qu.empty()){
        int node=qu.front();
        qu.pop();
        cout<<node<<" ";
        //now visit the neighbours and reduce the neighbours indegree and if indegree=0 then push into the queue
        for(auto neighbour:graph[node]){
            if(not visited.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }

    }

}




int main(){
    cin>>v;
    graph.resize(v,list<int>());

    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);
        
    }

    topologicalSortBFS();

    return 0;
}


// 8 10
// 0 2
// 1 2
// 1 3
// 2 3 
// 2 4
// 2 5 
// 2 6
// 4 6
// 5 6
// 6 7
// 0 1 2 3 4 5 6 7