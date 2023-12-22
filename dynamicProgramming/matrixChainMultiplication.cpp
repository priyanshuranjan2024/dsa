#include<bits/stdc++.h>
using namespace std;

//ques
// Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is 
// (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the 
// total number of element multiplications is minimum.


// Examples:

// Input: arr[] = {40, 20, 30, 10, 30}

// Output: 26000

// Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.

// Let the input 4 matrices be A, B, C and D.

// The minimum number of  multiplications are obtained by 

// putting parentheses in the following way (A(BC))D.

// The minimum is 20*30*10 + 40*20*10 + 40*10*30


// Input: arr[] = {1, 2, 3, 4, 3}

// Output: 30

// Explanation: There are 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3. 

// Let the input 4 matrices be A, B, C and D.  

// The minimum number of multiplications are obtained by 

// putting parentheses in the following way ((AB)C)D.

// The minimum number is 1*2*3 + 1*3*4 + 1*4*3 = 30



//if we multiply two matrices A and B of order nxm and mxk then total no. of multiplication will be n*m*k;


vector<vector<int>> dp;//2d dp as we need two variables to define the state of the problem

int f(int i,int j,vector<int> &arr){
    if(i==j or i+1==j) return 0;//these are the base case that is only one element or only one matrix

    if(dp[i][j]!=-1) return dp[i][j];
    
    //k is the partition variable as if we have to find out the best answer then we must have the min cost for all less parition
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,f(i,k,arr)+f(k,j,arr)+arr[i]*arr[k]*arr[j]);

    }

    return dp[i][j]=ans;

}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    dp.clear();
    dp.resize(1005,vector<int> (1005,-1));

    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<f(0,n-1,arr)<<endl;





    return 0;
}

// 5
// 40 20 30 10 30
// 26000