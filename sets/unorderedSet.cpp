#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    //will print in any  order random
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}