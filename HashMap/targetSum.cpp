#include<bits/stdc++.h>
using namespace std;

// Given an array of length n and a target, return a pair whose sum is equal to the target. If there is no pair 
// present, return -1.

//first approach brute force o(n^2) nested loop
//second approach is the two pointer approach but we will have to sort the array first o(logn)
//third approach o(n) using map and storing previous elements


vector<int> targetSumPair(vector<int> &arr,int targetSum){
    unordered_map<int,int> m;//map to store the array element with its index
    vector<int> ans(2);//answer vector
    

    for(int i=0;i<arr.size();i++){
        if(m.find(targetSum-arr[i])!=m.end()){
            ans[0]=m[targetSum-arr[i]];//index
            ans[1]=i; 

            return ans;          
        }
        else{
            //just add the element to the map with index as its value
            m[arr[i]]=i;
        }
    }

    return ans;
}




int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    int targetSum;
    cin>>targetSum;

    vector<int> ans=targetSumPair(arr,targetSum);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}