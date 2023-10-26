#include<bits/stdc++.h>
using namespace std;

//for a given array  and an integer x, find the
//minimum subarray size for which sum>x.

int smallestSubArrayWithSum(int arr[],int n,int x){
    int sum=0;int minLength=n+1;int start=0;int end=0;
    //this loop will run until end<n;
    while(end<n){
        //run this loop until sum<=x
        while(sum<=x && end<n){
            sum+=arr[end++];
        }
        //now try to decrease the size of the sliding window if possible
        while(sum>x && start<n){
            minLength=min(minLength,(end-start));
            
            sum-=arr[start++];

        }
    }

    return minLength;
}

int main(){

    int arr[]={1,4,45,6,10,19};
    int n=6;
    int x=51;
    
    int minLength=smallestSubArrayWithSum(arr,n,x);
    if(minLength==(n+1)){
        cout<<"No subarray is possible with these conditions"<<endl;
    }
    else{
        cout<<minLength<<endl;
    }
    
    return 0;
}