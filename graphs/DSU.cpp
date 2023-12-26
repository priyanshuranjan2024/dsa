#include<bits/stdc++.h>
using namespace std;

//both function has time complexity O(log*n) that is nearly  equal to constant

int find(vector<int> &parent,int x){
    //this method will return which group or cluster x belongs to by returning the leader of the group

    //we will store the result in the parent vector so as to apply path compression
    return parent[x]=(parent[x]==x)?x:find(parent,parent[x]);

}

void Union(vector<int>&parent,vector<int>&rank,int a,int b){
    //find the parent element of a and b
    a=find(parent,a);
    b=find(parent,b);

    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
    }
    else{
        rank[b]++;
        parent[a]=b;
    }

}

int main(){

    int n;
    cin>>n;//no. of the elements
    vector<int> parent(n+1);//for 1-based indexing
    vector<int> rank(n+1,0);

    for(int i=0;i<=n;i++) parent[i]=i;

    string s;
    cin>>s;

    if(s=="union"){
        int a,b;
        cin>>a>>b;
        Union(parent,rank,a,b);
    }
    else if(s=="find"){
        int x;
        cin>>x;
        cout<<find(parent,x)<<endl;
    }


    return 0;
}