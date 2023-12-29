#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<list<pair<int,int>>> graph;//weighted graph

void add_edge(int a,int b,int wt,bool bi_dir=true){
    graph[a].push_back({b,wt});
    if(bi_dir) graph[b].push_back({a,wt});

}



ll prims(int src,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//since it should be minheap
    //this will have pair{wt,neighbour(node)}

    unordered_set<int> vis;
    pq.push({0,src});

    unordered_map<int,int> mp;
    //initially all elements distance will be infinity except src whose will be -1
    for(int i=1;i<=n;i++) mp[i]=INT_MAX;
    mp[src]=0;
    vector<int> parent(n+1);//helpful if asked to print the mst and n is the number of vertices since 1 based indexing

    int total_edges=0;//0->n-1
    int result=0;//this will store the sum of the weights in final mst



    while(total_edges<n and not pq.empty()){
        pair<int,int> curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;//this is to handle the non updated case in the pq
            
        }

        vis.insert(curr.second);
        total_edges++;
        result+=curr.first;
        pq.pop();

        //traverse all over its neighbours 
        for(auto neighbour:graph[curr.second]){
            if(not vis.count(neighbour.first) and mp[neighbour.first]>neighbour.second){
                pq.push({neighbour.second,neighbour.first});//neighbour.second is wt and neighbour.first is the node value
                parent[neighbour.first]=curr.second;
                //update the map
                mp[neighbour.first]=neighbour.second;

            }
        }


    }

    return result;


}




int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1,list<pair<int,int>>());
    while(m--){
        int s,d,w;
        cin>>s>>d>>w;
        add_edge(s,d,w);
    }

    int src;//for prims algorithm
    cin>>src;

    cout<<prims(src,n)<<endl;




    return 0;
}

//refer gfg its implementation is easier