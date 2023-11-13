#include<bits/stdc++.h>
using namespace std;
int const N=1e3;

void heapify(int arr[],int &size, int curr){
    //same code as that for deletion
    //traverse till it is not the leaf node
    while(2*curr<=size){
        int leftchild=2*curr;
        int rightchild=2*curr+1;
        int minchild=leftchild;
        //check if rightchild exits or not
        if(rightchild<=size && arr[rightchild]<arr[leftchild]){
            minchild=rightchild;
        }

        //now check if minchild is greater than curr or not
        if(arr[minchild]>=arr[curr]){
            return;
        }

        //otherwise swap and update the value of the curr
        swap(arr[minchild],arr[curr]);
        curr=minchild;

    }

}

int main(){
    int arr[N]={-1,60,10,80,50,5,20,70};
    int size=7;
    //create a loop to call the function heapify for each parent node
    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);
        //where i is the index of the parent node

    }

    //now print
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    
    return 0;
}