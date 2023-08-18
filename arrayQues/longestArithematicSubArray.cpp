#include<iostream>
using namespace std;
// intution and approach
// loop over thr array and find the answer.
// maintain the following variable:
// 1.previous common difference(pd)
// 2.current arithmetic subarray length(curr)
// 3.max arithematic subarray length(ans)
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=2;//denote the length of maximum subarray
    int pd=arr[1]-arr[0];//starting difference
    int j=2;//iterating variable
    int curr=2;//current length

    //algorithm
    while(j<n){
        if(pd==arr[j]-arr[j-1]){
            curr++;
        }
        else{
            pd=arr[j]-arr[j-1];
            curr=2;
        }
        ans=max(ans,curr);
        j++;

        
    }

    cout<<ans<<endl;


    return 0;

}