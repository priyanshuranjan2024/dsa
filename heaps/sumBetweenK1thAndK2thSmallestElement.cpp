#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int size,int curr){
    while(2*curr+1<size){
        int leftchild=2*curr+1;
        int rightchild=2*curr+2;
        int minchild=leftchild;

        if(rightchild<size && arr[rightchild]<arr[leftchild]){
            minchild=rightchild;
        }

        if(arr[minchild]>=arr[curr]){
            return ;
        }
        
        swap(arr[minchild],arr[curr]);
        curr=minchild;

    }
}

int removeFromArray(int arr[],int &size){
    int removeValue=arr[0];

    arr[0]=arr[size-1];
    size--;
    heapify(arr,size,0);

    return removeValue;
}

int sumOfSmallest(int arr[],int size,int k1,int k2){
    //create minheap

    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }

    int sum=0;
    int elements=k2-k1-1;//no. of elements whose sum we have to find since k1 and k2 are not included
    //remove k1 elements
    while(k1--){
        removeFromArray(arr,size);

    }

    //calculate sum by removing elements k2-k1 times
    while(elements--){
        sum+=removeFromArray(arr,size);
    }

    return sum;

}


int main(){

    int arr[7]={20,8,22,4,12,10,14};
    int size=7;
    int k1=3;
    int k2=6;

    cout<<sumOfSmallest(arr,size,k1,k2)<<endl;

    return 0;
}