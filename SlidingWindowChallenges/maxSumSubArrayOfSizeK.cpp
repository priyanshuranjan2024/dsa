#include<bits/stdc++.h>
using namespace std;

//for a given arrayand integers k and x
//find the maximum sum subarray of size k
//and havind sum less than x.

void maxSubArraySum(int arr[],int n,int k,int x){
    int sum=0;
    int ans=0;

    //calculate the sum of first k elements and check whether it is ok to be the ans
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }

    if(sum<x){
        ans=sum;
    }

    //now slide the window
    for(int i=k;i<n;i++){
        sum=sum-arr[i-k];
        sum=sum+arr[i];

        if(sum<x){
            ans=max(ans,sum);
        }
    }

    cout<<"The maximum subarray sum is "<<ans<<endl;

}


int main(){
    int arr[]={7,5,4,6,8,9};
    int k=3;
    int x=20;
    int n=6;

    maxSubArraySum(arr,n,k,x);//18

    return 0;
}