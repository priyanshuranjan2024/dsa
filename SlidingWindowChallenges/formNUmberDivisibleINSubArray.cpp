#include<bits/stdc++.h>
using namespace std;

//for a given array and an integer k,
//check if any subarray of size k exists
//in the array such that elements in the 
//subarray form a number divisible by 3

void  computeNumberFromSubArray(vector<int> arr,int k){
    pair<int,int> ans;//indices from starting to ending of the resulting sub array
    int sum=0;

    //calculate sum for first k elements
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }

    bool found=false;
    if(sum%3==0){
        ans=make_pair(0,k-1);
        found=true;
    }

    //sliding window technique
    for(int j=k;j<arr.size();j++){
        if(found){
            break;
        }

        sum=sum+arr[j]-arr[j-k];

        if(sum%3==0){
            ans=make_pair(j-k+1,j);
            found=true;
        }
    }

    if(!found){
        ans=make_pair(-1,0);//that is never found
    }

    //now
    if(ans.first==-1){
        cout<<"The subarray is not found"<<endl;
    }

    else{
        //print all the elements of the subarray
        for(int i=ans.first;i<=ans.second;i++){
            cout<<arr[i]<<" ";
        }
    }


}

int main(){

    vector<int> arr={84,23,45,12,56,82};
    int k=3;

    computeNumberFromSubArray(arr,k);
    


    return 0;
}