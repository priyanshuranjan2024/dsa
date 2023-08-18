
// #include "bits/stdc++.h"
// using namespace std;
// //brute force approach time complexity O(n^3)
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
        
//     }

//     int maxSum=INT_MIN;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){
//                 sum+=arr[k];

//             }
//             maxSum=max(sum,maxSum);//updating the value of maxSum
//         }
//     }
//     cout<<maxSum<<endl;
//     return 0;
// }






// //CUMULATIVE  SUM APPROACH TIME COMPLEXITY O(N^2)   //need to learn again
// #include "bits/stdc++.h"
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     int currentSum[n+1];
//     currentSum[0]=0;

//     for(int i=1;i<=n;i++){
//         currentSum[i]=currentSum[i-1]+arr[i-1];
//     }

//     int maxSum=INT_MIN;
//     for(int i=1;i<=n;i++){
//         int sum=0;
//         for(int j=0;j<i;j++){
//             sum=currentSum[i]-currentSum[j];
//             maxSum=max(sum,maxSum);
//         }
//     }

//     cout<<maxSum<<endl;
//     return 0;
// }



//KADANE'S ALGORITHM TIME COMPLEXITY O(N)
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int currentSum=0;
    int maxSum=INT_MIN;


    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        if(currentSum<0){
            currentSum=0;
        }
        maxSum=max(maxSum,currentSum);
    }

    cout<<maxSum<<endl;
    return 0;



}