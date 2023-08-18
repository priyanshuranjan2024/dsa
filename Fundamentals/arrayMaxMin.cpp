#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    //input
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }

    int maxNo=INT_MIN;
    int minNo=INT_MAX;
    for(int i=0;i<n;i++){
        // if(arr[i]>maxNo){
        //     maxNo=arr[i];
        // }

        // if(arr[i]<minNo){
        //     minNo=arr[i];
        // }

        maxNo=max(arr[i],maxNo);
        minNo=min(arr[i],minNo);
    }
    cout<<maxNo<<" "<<minNo;


}