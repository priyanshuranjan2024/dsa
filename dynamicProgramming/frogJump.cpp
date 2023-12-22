#include<bits/stdc++.h>
using namespace std;

//ques
// There are N stones, numbered 1,2,…,N. The height of ith stone is hi.

// There is a frog who is initially on Stone 1. He will repeat an action some number of times to reach Stone N. The 
// action is that if the frog is currently on Stone i, it jumps to one of the following: Stone i+1,i+2,…,i+K. Here, a cost 
// of |hi - hj| is incurred, where j is the stone to land on.

// Find the minimum possible total cost incurred before the frog reaches Stone N.

// Input1:

// n = 5 

// k = 3

// 10 30 40 50 20

// Output1:

// 30


// Input2:

// 3 1

// 10 20 10

// Output2:

// 20


vector<int> dp;

//mainly the thing is that in top down approach we don't have to find the order whereas we have to find the order in case of bottom up solution

int f(vector<int>& heights,int i,int k){
    //base case
    if(i==heights.size()-1) return 0;
    if(dp[i]!=-1) return dp[i];


    int ans=INT_MAX;
    
    for(int j=1;j<=k;j++){
        //check if it jumps outside of the vector
        if(i+j>=heights.size()) break;

        ans=min(ans,abs(heights[i]-heights[i+j])+ f(heights,i+j,k));


    }

    return dp[i]= ans;
}

int fbu(vector<int> & heights,int k){
    dp.clear();
    dp.resize(10005,INT_MAX);//since we have to find minimum cost

    int n=heights.size();
    dp[n-1]=0;

    for(int i=n-2;i>=0;i--){  //to get the order
        for(int j=1;j<=k;j++){
            if(i+j>=n) break;

            dp[i]=min(dp[i],abs(heights[i]-heights[i+j])+dp[i+j]);
        }
    }

    return dp[0];
}


int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;

    dp.clear();
    dp.resize(10005,-1);


    vector<int> v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<f(v,0,k)<<endl;//this will return the minimum cost to jump from the initial to the final stone
    cout<<fbu(v,k)<<endl;



    return 0;
}