#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<list<pair<int,int>>> graph;

void add_edge(int a,int b,int wt,bool bi_dir=true){
    graph[a].push_back({b,wt});
    if(bi_dir) graph[b].push_back({a,wt});

}



unordered_map<int,int> dijkstras(int src,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//since it should be minheap
    

    unordered_set<int> vis;
    pq.push({0,src});

    unordered_map<int,int> mp;
    //initially all elements distance will be infinity except src whose will be -1
    for(int i=0;i<n;i++) mp[i]=INT_MAX;
    mp[src]=0;
    vector<int> via(n);//helpful if asked to print the mst and n is the number of vertices since 1 based indexing

    



    while( not pq.empty()){
        pair<int,int> curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;//this is to handle the non updated case in the pq
            
        }

        vis.insert(curr.second);
        pq.pop();

        //traverse all over its neighbours 
        for(auto neighbour:graph[curr.second]){
            if(not vis.count(neighbour.first) and mp[neighbour.first]>mp[curr.second]+neighbour.second){

                pq.push({mp[curr.second]+neighbour.second,neighbour.first});//neighbour.second is wt and neighbour.first is the node value
                via[neighbour.first]=curr.second;
                //update the map
                mp[neighbour.first]=mp[curr.second]+neighbour.second;

            }
        }


    }

    return mp;


}




int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n,list<pair<int,int>>());
    while(m--){
        int s,d,w;
        cin>>s>>d>>w;
        add_edge(s,d,w);
    }

    int src;//for prims algorithm
    cin>>src;

    unordered_map<int,int> sp=dijkstras(src,n);

    int dest;
    cin>>dest;
    cout<<sp[dest]<<endl;//this will give the shortest path from src to dest using dijkstras algorithm
    //path can be given using via array




    return 0;
}
