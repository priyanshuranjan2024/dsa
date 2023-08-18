#include<iostream>
using namespace std;
int main(){
    //firstly taking the array from the user
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //bubble sort
    int count=1;//will keep track of the no. of times loop will be done
    while(count<n){
        for(int i=0;i<n-count;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        count++;

    }
    //printing the sorter array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
     
}