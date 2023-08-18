#include<iostream>
using namespace std;
//refer to https://youtu.be/13ocRMSJy5M
//create a function binarySearch
int binarySearch(int arr[],int n,int key){
    int start=0;
    int end=n;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;

        }
        else if(arr[mid]>key){
            end=mid-1;

        }
        else{
            start=mid+1;
        }
    }
    return -1;

}
int main(){
    int n;
    cin>>n;
    int arr[n]; //needs to be a sorted array
    //input
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    int key;
    cin>>key;
    cout<<binarySearch(arr,n,key);
    return 0;
}