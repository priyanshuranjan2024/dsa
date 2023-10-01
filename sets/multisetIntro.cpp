#include<bits/stdc++.h>
using namespace std;



int main(){
    multiset<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(2);

    s1.erase(2);

    for(auto i:s1){
        cout<<i<<" ";
    }
    cout<<endl;

    //note if we give value in erase function of multiset then all instances of the value will be deleted
    // if we want to delete only one instance then we will use s1.erase(s1.find(<value>)) which will give the pointer of the first instance to the erasae function
    

    return 0;
}