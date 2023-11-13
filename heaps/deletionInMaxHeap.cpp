#include<bits/stdc++.h>
using namespace std;
int const N=1e3;

void deletionInMaxHeap(int arr[],int size){
    arr[1]=arr[size];
    size--;
    int curr=1;

    while (2*curr<=size)
    {
        int leftchild=2*curr;
        int rightchild=2*curr+1;
        int maxchild=leftchild;
        if(rightchild<=size && arr[rightchild]>arr[leftchild]){
            maxchild=rightchild;
        }

        if(arr[maxchild]<=arr[curr]){
            return;
        }

        swap(arr[maxchild],arr[curr]);
        curr=maxchild;
    }
    
}

int main(){

    int maxHeap[N]={-1,90,80,70,20,10,50,60};
    int size=7;
    deletionInMaxHeap(maxHeap,size);

    //print
    for(int i=0;i<=size;i++){
        cout<<maxHeap[i]<<" ";

    }
    cout<<endl;

    return 0;
}