#include<bits/stdc++.h>
using namespace std;

// Q3 Given an array of n integers. You are supposed to perform k operations on it. At each operation, the 
// smallest 2 elements of the array are removed from the array, multiplied by each other, and the product is 
// added back to the array.

// Return the largest element of the array after the k operations.

// It is guaranteed that at least one element will remain after the k operations.

// Input:

// n = 5, k = 3

// Array = {2 4 3 1 5}


//firstly create a min heap
// then k times pop two top elements from the heap and push back their product 
//pop till heap size is 1 to get the largest element after k operations



int largestPoint(vector<int> a,int n,int k){

    priority_queue<int,vector<int>,greater<int>> pq;//min heap created
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }

    for(int i=0;i<k;i++){
        //remove two elements smallest
        int ele1=pq.top();
        pq.pop();
        int ele2=pq.top();
        pq.pop();

        int product=ele1*ele2;
        pq.push(product);





    }

    //now remove till the size of min heap is 1 to get the largest element
    while(pq.size()>1){
        pq.pop();
    }

    return pq.top();

}



int main(){

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a){
        cin>>x;
    }

    cout<<largestPoint(a,n,k)<<endl;

    

    return 0;
}


// 5 3
// 2 4 3 1 5
// 20