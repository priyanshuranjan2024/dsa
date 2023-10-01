#include<bits/stdc++.h>
using namespace std;

//question
//given is an array with n elements that represent n positions
// along a straight line. Find k elements such that the minimum distance
// between  any  2 elements is the maximum possible.

bool isFeasible(int mid, int arr[],int n,int k){
    //create two variable one pos and other element 
    //if element ==k then it is feasible otherwise not
    int pos=arr[0];
    int element=1;

    //traversing in the sorted array 
    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            //update postion for next traversal
            pos=arr[i];
            //update element
            element++;
            //check if element is equal to k or not
            if(element==k){
                return true;
            }

        }

    }

    //if element is not equal to k in the whole traversal
    return false;

}


int largestMinimumDistance(int arr[],int n,int k){
    //firstly sort the array for binary search
    sort(arr,arr+n);


    int result=-1;
    //for traversing
    int left=1;
    int right=arr[n-1];

    //binary search
    while(left<right){
        //calculate mid
        int mid=(left+right)/2;

        if(isFeasible(mid,arr,n,k)){
            //then search in right side of the mid
            //firstly update the result
            result=max(mid,result);
            left=mid+1;
        }
        else{
            //search in left side
            right=mid;
        }
    }

    //finally return the  result
    return result;
}



int main(){
    int arr[]={1,2,8,4,9};
    int n=5;
    int k=3;

    cout<<largestMinimumDistance(arr,n,k)<<endl; //3



    return 0;
}