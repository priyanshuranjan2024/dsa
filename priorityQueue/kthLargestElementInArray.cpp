#include<bits/stdc++.h>
using namespace std;


int kthLargestElementInArray(vector<int> arr,int n,int k){
    //create a min heap
    priority_queue<int,vector<int>,greater<int>> pq;

    //traverse the array and push elements into queue but if pq.size()>k then pq.pop()
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }

    //now the top element will be the kth largest element
    return pq.top();

}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);

    //taking the input
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    cout<<kthLargestElementInArray(arr,n,k)<<endl;

    return 0;
}

// 5
// 3
// 3 7 2 9 5
// 5