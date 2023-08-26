#include<bits/stdc++.h>
using namespace std;

//vector is a dynamic array

int main(){
    vector<int> v;//initialising a vector

    //v.puch_back() functions pushes the content at the end of the vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //v.pop_back() deletes the last added element from the vector
    v.pop_back();

    //printing the contents
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    //printing the contents using iterator
    vector<int>::iterator itr;
    for(itr=v.begin();itr!=v.end();itr++){
        cout<<*itr<<endl;
    }

    //printing the contents using auto 
    for(auto element:v){
        cout<<element<<endl;
    }

    //defining a vector of our size and all same elements
    vector<int> v2(3,50);// 50 50 50
    

    swap(v,v2);//swap the two vectors

    sort(v.begin(),v.end());//for sorting




    return 0;
}