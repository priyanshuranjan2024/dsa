//given an array a[] of size n. output sum of wach subarray of the given array.
#include<iostream>
using namespace std;
int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int currentSum=0;
    int count=0;//will count the number of subarrays

    //nested loop
    for(int i=0;i<n;i++){
        currentSum=0;
        for(int j=i;j<n;j++){
            currentSum+=arr[j];
            cout<<currentSum<<endl;//will print each and every subarray's sum
            count++;

        }
    }
    cout<<count;
    return 0;
}