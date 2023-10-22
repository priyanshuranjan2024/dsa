#include<bits/stdc++.h>
using namespace  std;


//now make the function for finding if the combination will be feasible to be a solution or not 
//it must return minimum  no. of painters for that
int findFeasible(int boards[],int n,int limit){
    int sum=0;
    int paintersRequired=1;

    //traversing through the array boards
    for(int i=0;i<n;i++){
        sum+=boards[i];
        if(sum>limit){
            sum=boards[i];
            //now increase the no. of painters required
            paintersRequired++;
        }
    }

    return paintersRequired;
}

//array boards[] contain size of the all boards
int paintersParition(int boards[],int n,int m){
    int totalLength=0;//for storing the sum of all the board length
    int k=0;//for storing the maximum lenght 

    for(int i=0;i<n;i++){
        k=max(k,boards[i]);
        totalLength+=boards[i];
    }

    //now defining the parameters of the binary search
    int low=k;//this will be returned as the answer

    int high=totalLength;

    while(low<high){
        int mid=(low+high)/2;
        int painters=findFeasible(boards,n,mid);//for checking the feasibility
        if(painters<=m){
            high=mid;//search in the left half now for more minimum

        }
        else{
            //search in the right half 
            low=mid+1;
        }

        

    }

    return low;

}

int main(){
    int arr[]={10,20,30,40};
    int n=4;
    int m=2;


    cout<<paintersParition(arr,n,m)<<endl;//60 is the answer 


    return 0;
}