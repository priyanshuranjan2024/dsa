//we are given a ascending and sorted array that has been from a pivoted point(unknown to us) and an element x.
//search for element x in the array with complexity less than that of linear search O(N)

#include<bits/stdc++.h>
using namespace std;

int searchInRotatedArray(int arr[],int key,int left,int right){
    //left and right are the binary search exteremetes
    if(left>right){
        return -1;
    }

    int mid=(left+right)/2;
    if(arr[mid]==key){
        return mid;
    }
    //mainly searching for pivot now

    //else i will check three conditions
    if(arr[left]<=arr[mid]){
        //then check this condition
        if(key>=arr[left] && key<=arr[mid]){
            //search in the left half of the pivot point
            return searchInRotatedArray(arr,key,left,mid-1);
        }

        //else search the right half
        return searchInRotatedArray(arr,key,mid+1,right);
    }

    if(key>=arr[mid] && key<=arr[right]){
        return searchInRotatedArray(arr,key,mid+1,right);
    }

    //if both above conditions are false then search in left half only
    return searchInRotatedArray(arr,key,left,mid-1);

}


int main(){

    int arr[]={6,7,8,9,10,1,2,5};
    int n=8;
    int key=8;
    int idx=searchInRotatedArray(arr,key,0,n-1);//this is the index

    if(idx==-1){
        cout<<"Key is not present in the array"<<endl;
    }else{
        cout<<"Key is present in the array at index: "<<idx<<endl;
    }



    return 0;
}