// problem--> given an unsorted array of size n of positive integers, _find
// a continuous subarray which adds to given number s. then output the starting and ending index from the main array


#include "bits/stdc++.h"
using namespace std;
int main(){
    // //brute force with time complexity of O(n^2)


    // //taking input the array
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // int key;
    // cin>>key;//the sum to be compared with


    
    // int currentSum=0;
    // //calculating the sum of all subarrays
    // for(int i=0;i<n;i++){
    //     currentSum=0;

    //     for(int j=i;j<n;j++){
    //         currentSum+=arr[j];
    //         if(currentSum==key){
    //             cout<<arr[i]<<" "<<arr[j]<<endl;//starting and ending element 
    //         }

    //     }

    // }
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //create two pointers
    //and create two pointer end and start and also intialise i and j
    int i=0,j=0,start=-1,end=-1,sum=0;
    while(j<n && sum+arr[j]<=s){
        sum+=arr[j];
        j++;
    }

    if(sum==s){
        cout<<i<<" "<<j<<endl;
        return 0;
    }

    while(j<n){
        sum+=arr[j];
        while(sum>s){
            sum-=arr[i];
            i++;

        }
        if(sum==s){
            start=i;
            end=j;
            break;
        }
        j++;
    }
    cout<<start<<" "<<end<<endl;
    return 0;   
    

    
}