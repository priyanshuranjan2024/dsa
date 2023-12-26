#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
unordered_set<int> visited;




void add_edge(int curr,int dest,bool bi_dir=true){
    graph[curr].push_back(dest);

    if(bi_dir) graph[dest].push_back(curr);



}

void bfs(int src,int dest,vector<int>& dist){
    queue<int> q;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src]=0;//distance from src to src

    visited.insert(src);
    q.push(src);

    //we have to empty the q
    while(!q.empty()){
        int curr=q.front();
        q.pop();

        //now search the next level
        for(auto neighbour:graph[curr]){
            if(not visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
                dist[neighbour]=dist[curr]+1;//this is the distance of neighbour from the src

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

        add_edge(s,d);

    }

    vector<int> dist;

    bfs(0,6,dist);

    for(auto ele:dist) cout<<ele<<" ";



    return 0;
}