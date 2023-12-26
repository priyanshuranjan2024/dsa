#include<bits/stdc++.h>
using namespace std;

//first a global vector of linked list
vector<list<int>> graph;
//if we want weighted then we will have pair in linked list rather than only int
vector<list<pair<int,int>>> weighted_graph;

int v;//no. of vertices
// void add_edge(int src,int dest,int wt,bool bi_dir=true){
//     graph[src].push_back(dest);
//     if(bi_dir){
//         graph[dest].push_back(src);
//     }



// }

//for weighted graph
void add_edge(int src,int dest,int wt,bool bi_dir=true){
    weighted_graph[src].push_back({dest,wt});
    if(bi_dir){
        weighted_graph[dest].push_back({src,wt});
    }

}

void display(){
    for(int i=0;i<weighted_graph.size();i++){
        cout<<i<<"->"<<" ";
        //traverse over the linked list
        for(auto el:weighted_graph[i]) cout<<el.first<<" "<<el.second<<", ";//printing neighbour
        cout<<endl;

    }
}

int main(){

    cin>>v;
    weighted_graph.resize(v,list<pair<int,int>>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        // add_edge(s,d);//if undirected
        add_edge(s,d,wt,false);
    }

    display();



    return 0;
}

// 7
// 6
// 0 1
// 0 2
// 1 5
// 2 3
// 3 6
// 6 4
// 0-> 1, 2,
// 1-> 0, 5,
// 2-> 0, 3,
// 3-> 2, 6,
// 4-> 6,
// 5-> 1,
// 6-> 3, 4,0 1



// 7 7 
// 0 1 6
// 0 2 3
// 1 5 1
// 2 7 8
// 2 3 6 
// 3 6 9
// 6 4 7
