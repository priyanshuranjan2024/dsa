#include<iostream>
using namespace std;

int firstOcc(int arr[],int n,int i,int key){
    //base condition
    if(i==n){
        return -1;//that means not found
    }
    if(arr[i]==key){
        return i;
    }
    firstOcc(arr,n,i+1,key);
}

int lastOcc(int arr[],int n,int i,int key){
    //base condition
    if(i==n){
        return -1;
    }
    int restArray=lastOcc(arr,n,i+1,key);
    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;//if not found

}



int main(){
    int n;
    cin>>n;
    int arr[n];
    int z=0;//pointer to traverse in recursive function
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    int key;
    cin>>key;
    cout<<firstOcc(arr,n,z,key)<<" "<<lastOcc(arr,n,z,key);
}