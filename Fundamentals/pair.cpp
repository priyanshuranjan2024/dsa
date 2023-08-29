#include<bits/stdc++.h>
using namespace std;

//reduce the array
bool myCompare(pair<int,int> p1,pair<int,int>p2){
    return p1.first<p2.first;
}



int main(){
    int arr[]={10,16,7,14,5,3,12,9};

    vector<pair<int,int>> v;
    //now put the values in the vector

    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        v.push_back(make_pair(arr[i],i));
    }
    //now sort this vector
    sort(v.begin(),v.end(),myCompare);
    //now replace these value in the array

    for(int i=0;i<v.size();i++){
        arr[v[i].second]=i;

    }
    //now printing the array
    for(int i=0;i<v.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}