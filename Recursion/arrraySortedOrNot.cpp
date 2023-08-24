#include<iostream>
using namespace std;
//check if an array is sorted or not (recursively) strictly increasing)
bool sorted(int arr[],int n){
    if(n==1){
        return true;
    }
    
    bool restArray=sorted(arr+1,n-1);//recursive call
    return (arr[0]<arr[1] && restArray);
}




int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>n;
    }
    cout<<sorted(arr,n)<<endl;
    
    return 0;
}