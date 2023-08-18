// you are given an array of n integers including 0. The task is to find the smallest positve number missing from the array.
//approach
//1.buid a boolean check[] array that will depict if nay element x is present in the array or not.
//2.itereate over the array andmark non-neageative a[i] as True.
//now ,we iterate over check[] to find the index of 1st positive value.

//VIEW THE CODE ON GEEKSFORGEEKS

#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>n;
    }

    //creating check array

    const int N=1000;
    bool  check[N];
    for(int i=0;i<N;i++){
        check[i]=false;
    }

    //creating an answer variable which we will print
    
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            check[arr[i]]=true;

        }
    }
    int ans=-1;

    for(int i=1;i<N;i++){
        if(check[i]==false){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;
    return 0;

    
}