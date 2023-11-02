#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_multimap<string,int> fruit_count;

    //[] operator is not allowed in any kind of multimap

    fruit_count.insert(make_pair("apple",6));
    fruit_count.insert(make_pair("banana",5));
    fruit_count.insert(make_pair("apple",3));

    //printing the key value pair
    //using for each loop

    for(auto pair:fruit_count){
        cout<<"Fruit "<<pair.first<<endl;
        cout<<"No. of items "<<pair.second<<endl;
        cout<<endl;

    }
    
    return 0;
}