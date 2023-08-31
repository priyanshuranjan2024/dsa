#include<bits/stdc++.h>
using namespace std;
//count sort time complexity is O(n)

void countSort(int arr[],int n){
    int k=0;//maximum element in the array
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};//to count the number of occurence of all the elements
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }

    int ouput[n];
    for(int i=n-1;i>=0;i--){
        ouput[--count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=ouput[i];
    }




}



int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    countSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}