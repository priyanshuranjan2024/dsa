#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> kthClosestPoints(vector<pair<int,int>> pts,int n,int k){

    //firstly make a maxheap
    priority_queue<pair<int,pair<int,int>>> pq;
    //now traverse the vector and push into max heap
    for(auto &pt:pts){
        int distance=pt.first+pt.second;
        pq.push(make_pair(distance,pt));
        //remove k+1th largest elements
        if(pq.size()>k){
            pq.pop();
        }

    }

    vector<pair<int,int>> ans(k);
    //since we need in ascending order so we will fill ans vector from the back
    while(!pq.empty()){
        ans[pq.size()-1]=pq.top().second;
        pq.pop();

    }



    return ans;
}



int main(){
    int n,k;
    cin>>n>>k;

    //create a vector to store the coordinates
    vector<pair<int,int>> pts(n);
    //take the input using for each loop
    for(auto &pt:pts){
        cin>>pt.first>>pt.second;

    }

    vector<pair<int,int>> anspts=kthClosestPoints(pts,n,k);


    //now print the kth closest pair
    for(auto &pt1:anspts){
        cout<<pt1.first<<" "<<pt1.second<<endl;
    }


    return 0;

}

// 6
// 3
// 5 3
// 1 2
// 3 4
// 5 6
// 7 8
// 9 10


// 1 2
// 3 4
// 5 3