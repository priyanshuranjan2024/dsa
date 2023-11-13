#include<bits/stdc++.h>
using namespace std;
int const N=1e3;//defining the size of the array

void insertMinHeap(int arr[],int &size,int value){
    //firstly increase the size
    size++;
    arr[size]=value;
    //create a pointer pointing to current position
    int curr=size;

    while(curr/2>0 && arr[curr/2]>arr[curr]){
        swap(arr[curr/2],arr[curr]);
        //change the pointer position
        curr=curr/2;
    }

}


int main(){

    //firstly initialise the heap
    int minHeap[N]={-1,10,20,30,40,50};
    int size=5;
    int value=5;

    insertMinHeap(minHeap,size,value);
    //now display the array 
    for(int i=0;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }
    cout<<endl;

    return 0;
}