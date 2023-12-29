#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int>&parent,int x){
    
    return parent[x]=((parent[x]==x)?x:find(parent,parent[x]));
}

void Union(vector<int>&parent,vector<int>&rank,int a,int b){
    //find the leader
    a=find(parent,a);
    b=find(parent,b);

    if(a==b) return;
    
    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
    }
    else{
        rank[b]++;
        parent[a]=b;

    }


}

struct Edge
{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1,Edge e2){
    return e1.wt<e2.wt;
}

ll kruskals(vector<Edge>&input,int n){
    sort(input.begin(),input.end(),cmp);

    vector<int> parent(n+1);
    vector<int> rank(n+1,1);

    //initially make every node its parent
    for(int i=0;i<=n;i++){
        //since 1-based indexing
        parent[i]=i;

    }

    //in a tree edgeCount must be equal to n-1 where n is the no. of nodes
    int edgeCount=0;//n-1

    int i=0;
    ll ans=0;//this will be the final weight of the mst

    while(edgeCount<n-1 and i<input.size()){
        Edge curr=input[i];
        int srcPar=find(parent,curr.src);
        int destPar=find(parent,curr.dest);
        if(srcPar!=destPar){
            //this means that this will not form a cycle

            Union(parent,rank,srcPar,destPar);
            ans+=curr.wt;
            edgeCount++;

        }
        //doesn't matter if srcPar=destPar or not we will traverse to next edge
        i++;
    }

    return ans;

}



int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge> v(e);

    for(int i=0;i<e;i++) cin>>v[i].src>>v[i].dest>>v[i].wt;

    cout<<kruskals(v,n)<<endl;

    return 0;
}