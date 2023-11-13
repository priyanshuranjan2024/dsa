#include<bits/stdc++.h>
using namespace std;
int const N=1e3;

void heapify(int arr[],int n,int curr){
    //till it has child nodes heapify it 
    while(2*curr<=n){
        int leftchild=2*curr;
        int rightchild=2*curr+1;
        int maxchild=leftchild;


        if(rightchild<=n && arr[rightchild]>arr[leftchild]){
            maxchild=rightchild;

        }

        if(arr[maxchild]<=arr[curr]){
            return ;
        }

        swap(arr[maxchild],arr[curr]);
        //update the curr
        curr=maxchild;


    }

}


void deleteFromMaxHeap(int arr[],int &n){
    swap(arr[1],arr[n]);
    n--;
    //now heapify with parent as 1
    heapify(arr,n,1);

}

void heapsort(int arr[],int &n){
    //firstly call the heapify function for all the non-leaf nodes into maxheap
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    //now we will delete from the heap until its size becomes 0
    //this will be done by calling a function
    while(n>0){
        deleteFromMaxHeap(arr,n);
    }


}


int main(){

    int n=7;
    int arr[N]={-1,60,10,80,50,5,20,70};

    //call  the function heapsort
    heapsort(arr,n);

    //now print the sorted array
    for(int i=1;i<=7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}