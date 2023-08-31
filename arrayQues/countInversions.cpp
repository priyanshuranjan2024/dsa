#include<bits/stdc++.h>
using namespace std;
//problem statement
// count the inversions in the given array.
// two elements a[i] and a[j] form an inversion if a[i]>a[j] and i<j

//array ={3,5,6,9,1,2,7,8}

// //brute force approach time complexity O(n^2)
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     int count=0;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j] && i<j){
//                 count++;

//             }
//         }
//     }

//     cout<<count;
//     return 0;
// }

//using  merge sort technique

long long mergeThem(int arr[],int l,int mid,int r){
    long long inv=0;

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


            //important step
            inv+=n1-i;

            //a[i]>b[j] then a[i+1],a[i+2],...>b[j] && i<j
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

    return inv;

}






long long mergeSort(int arr[],int l, int r){
    long long inv=0;
    if(l<r){

        int mid=(l+r)/2;

        inv+=mergeSort(arr,l,mid);
        inv+=mergeSort(arr,mid+1,r);
        inv+=mergeThem(arr,l,mid,r);//merging the two sorted array parts


    }
    return inv;


}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mergeSort(arr,0,n-1)<<endl;

    return 0;
}