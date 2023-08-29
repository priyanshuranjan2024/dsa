#include<bits/stdc++.h>
using namespace std;
//given an array num of distinct integers return all the possible permutations. You can return the answers the answer in any order


// //method 1 
vector<vector<int>> ans;

void permute(vector<int> &a,int idx){
    if(idx==a.size()){
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++){
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx]);
    }
    return;

}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a){
        cin>>i;
    }

    cout<<endl;




    //method 2 using stl trick
    sort(a.begin(),a.end());
    do{
        ans.push_back(a);
    }
    while(next_permutation(a.begin(),a.end()));




    // permute(a,0); //method 1
    
    for(auto v:ans){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}



//method 2 shortcut using stl trick
//firstly sort the array then call next_permutation()