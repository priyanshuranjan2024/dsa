#include<bits/stdc++.h>
using  namespace std;
int const N=1e3;

void deletionInMinHeap(int minHeap[],int &size){
    //swap the root and the last node
    minHeap[1]=minHeap[size];
    size--;
    int curr=1;

    while(2*curr<=size){
        //will have atleast one child node
        int leftchild=2*curr;
        int rightchild=2*curr+1;
        int minchild=leftchild;
        //now check if the rightchild is present or not
        if(rightchild<=size && minHeap[rightchild]<minHeap[leftchild]){
            minchild=rightchild;
        }

        //we now have the minchild
        //check if minchild satisfy the condition
        if(minHeap[minchild]>=minHeap[curr]){
            return;
        }

        //otherwise
        //swap the value
        swap(minHeap[minchild],minHeap[curr]);
        curr=minchild;
    }

}


int main(){
    int minHeap[N]={-1,10,20,30,40,50};
    int size=5;
    
    //deletion only happens at the root
    deletionInMinHeap(minHeap,size);

    for(int i=0;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }
    cout<<endl;

    return 0;
}