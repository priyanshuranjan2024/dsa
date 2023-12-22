#include<bits/stdc++.h>
using namespace std;

//ques
// Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, 
// The task is to find the number of ways to make a sum by using different combinations from coins[]. Assume 
// that you have an infinite supply of each type of coin.

// Input1: sum = 4, coins[] = {1,2,3}, 

// Output1: 4


int fbu(int sum,vector<int>& coins){
    vector<int> dp(100005,0);//since we may have to sum
    int MOD=1000000007;
    dp[0]=1;//picking nothing at all

    for(int j=0;j<coins.size();j++){
        for(int i=1;i<=sum;i++){
            if(i-coins[j]<0) continue;
            dp[i]=(dp[i]%MOD+dp[i-coins[j]]%MOD)%MOD;
        }
    }

    return dp[sum];

    
}


int main(){
    int n;
    cin>>n;
    int sum;
    cin>>sum;

    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    cout<<fbu(sum,coins)<<endl;



    return 0;
}