#include<bits/stdc++.h>
using namespace std;

//based on recursion and divide and conquor algorithm



void mergeThem(int arr[],int l,int mid,int r){

    int n1=mid-l+1;
    int n2=r-mid;

    int a[n1];//temporary array
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }

    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    
    int i=0;
    int j=0;
    int k=l;//to traverse in the main array

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }

        else{
            arr[k]=b[j];
            k++;
            j++;
        }

    }

    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k]=b[j];
        k++;
        j++;
    }

}






void mergeSort(int arr[],int l, int r){
    if(l<r){

        int mid=(l+r)/2;

        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        mergeThem(arr,l,mid,r);//merging the two sorted array parts

    }


}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}