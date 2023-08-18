#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    int key;
    cin>>key;
    bool flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"found at index "<<i;
            flag=1;
        }
    }
    if(flag==0){
        cout<<"not found";
    }
    return 0;

}


