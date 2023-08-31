#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<(n+1);i++){
        if(i%2==0){
            arr[i]=arr[i/2];
        }

        else{
            arr[i]=arr[i/2]+arr[(i/2)+1];
        }
    }

    int maxNo=INT_MIN;
    for(int i=0;i<n+1;i++){
        maxNo=max(maxNo,arr[i]);
    }

    cout<<maxNo<<endl;
    return 0;
}