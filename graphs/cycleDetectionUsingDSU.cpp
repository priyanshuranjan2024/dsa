#include<bits/stdc++.h>
using namespace std;

//both function has time complexity O(log*n) that is nearly  equal to constant

int find(vector<int> &parent,int x){
    //this method will return which group or cluster x belongs to by returning the leader of the group

    //we will store the result in the parent vector so as to apply path compression
    return parent[x]=(parent[x]==x)?x:find(parent,parent[x]);

}

bool Union(vector<int>&parent,vector<int>&rank,int a,int b){
    //find the parent element of a and b
    a=find(parent,a);
    b=find(parent,b);
    //check if both have same parent then there will be cycle
    if(a==b) return true;

    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;//make parent of b as a
    }
    else{
        rank[b]++;
        parent[a]=b;
    }

    //if a and b don't have same parent
    return false;



}

int main(){
    

    int n;
    int q;//queries
    cin>>q;
    cin>>n;//no. of the elements
    vector<int> parent(n+1);//for 1-based indexing
    vector<int> rank(n+1,0);

    for(int i=0;i<=n;i++) parent[i]=i;

    while(q--){
        
        int a,b;
        cin>>a>>b;
        bool b=Union(parent,rank,a,b);
        if(b) cout<<"Cycle detected";
        else cout<<"No cycle detected";

    }

    

    

    return 0;
}