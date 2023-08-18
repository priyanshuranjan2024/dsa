#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+1];//to check the last element with two condition
    arr[n]=-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // //brute force method overall time complexity O(n^2)
    // //itreacting over each array and checking if it is a record breaking day or not
    // for(int i=0;i<n;i++){
    //     if(i==0){
    //         if(arr[i]>arr[i+1]){
    //             cout<<arr[i]<<endl;
    //         }
    //     }
    //     else{
    //         if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
    //             cout<<arr[i]<<endl;
    //         }

    //     }
    // }
    

    //optimised approach using max method time complexity O(n)
    int ans=0;
    int maximum=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>maximum && arr[i]>arr[i+1]){
            ans++;
        }
        maximum=max(maximum,arr[i]);
    }
    cout<<ans<<endl;
    
    
    return 0;

}