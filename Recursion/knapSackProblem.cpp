#include<bits/stdc++.h>
using namespace std;
//put n items with given weigth and value in a knapsack of capacity W to get the maximum total value in the knapsack
int maxKnapSack(int val[],int wt[],int n, int W){
    //base condition
    if(n==0 || W==0){
        return 0;
    }

    //if the weight of object is greater than W
    if(wt[n-1]>W){
        return maxKnapSack(val,wt,n-1,W);
    }

    return max(maxKnapSack(val,wt,n-1,W-wt[n-1])+val[n-1],maxKnapSack(val,wt,n-1,W));\

}

int main(){

    int wt[]={10,20,30};
    int val[]={100,50,150};
    int W=50;
    cout<<maxKnapSack(val,wt,3,W)<<endl;

    return 0;

}