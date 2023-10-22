#include<bits/stdc++.h>
using namespace std;
//for a given array,find the peak element in thearray. Peak element is one which
//than both,left and right neighbours of itself.

int findPeakElement(int arr[],int low, int high,int n){
    int mid=low+(high-low)/2;//this is because sometime (low+high)/2 doesn't work properly

    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 ||arr[mid]>=arr[mid+1])){
        return mid;
    }

    else if(mid>0 && arr[mid-1]>arr[mid]){
        return findPeakElement(arr,low,mid-1,n);
    }

    else if(mid>0 &&  arr[mid+1]>arr[mid]){
        return findPeakElement(arr,mid+1,high,n);
    }

}

int main(){
    int arr[]={0,6,8,5,7,9};
    int n=6;
    cout<<"The Peak  Element in the array has index "<<findPeakElement(arr,0,n-1,n)<<endl;

    return 0;
}