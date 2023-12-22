#include<bits/stdc++.h>
using namespace std;


//firstly create a vector to store the values  that are precomputed so as to optimize
vector<int> dp;


//this is the top down approach or memoization
int fibonacci(int n){
    //base condition
    if(n==0 or n==1){
        return n;
    }

    //we will check whether it is precomputed in the dp 
    if(dp[n]!=-1){
        return dp[n];
    }

    //but if is not calculated then we will firstly add it to the dp vector and then return it 

    return dp[n]=fibonacci(n-1)+fibonacci(n-2);

}


//this is the bottom up apporoach or tabulation
int fbu(int n){
    if(n==0 or n==1){
        return n;
    }

    //firstly resize the dp
    dp.resize(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    //use a loop for keeping the order
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];

    }

    return dp[n];

}

//more optimized method of tabulation
int fbuo(int n){
    if(n==0 or n==1){
        return n;
    }
    
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }

    return c;
}


int  main(){
    int n;
    cin>>n;
    //resize the dp to n+1 size and all its content should be -1
    dp.resize(n+1,-1);


    cout<<fibonacci(n)<<endl;

    cout<<fbu(n)<<" "<<fbuo(n)<<endl;

    return 0;
}

//note
//dp[n]==-1 it means that it the value of f(n) is not yet calculated
//dp[n]!=-1 it means that the value is calculated at not needed to pe calculated again