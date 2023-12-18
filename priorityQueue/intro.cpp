#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<int> pq1;//by default a maxHeap

    pq1.push(4);//inserting element

    pq1.push(7);
    pq1.push(2);
    pq1.push(10);

    //printing all the elements
    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;

    //now for min heap
    priority_queue<int,vector<int>,greater<int>> pq2;//min heap

    pq2.push(4);//inserting element

    pq2.push(7);
    pq2.push(2);
    pq2.push(10);

    //printing all the elements
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }




    return 0;
}