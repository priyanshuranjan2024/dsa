#include<bits/stdc++.h>
using namespace std;

int main(){
    // //set is an stl container which only contains unique values
    // set<int> s1;
    // s1.insert(1);
    // s1.insert(2);
    // s1.insert(3);
    // s1.insert(4); 


    // //to print the set we have to first declare a iterator and then use s.begin() and s.end()
    // set<int>::iterator itr;
    // //now use a for loop
    // for(itr=s1.begin();itr!=s1.end();itr++){
    //     //to print the value the pointer is pointing to use *itr
    //     cout<<*itr<<" ";

    // }
    // cout<<endl;

    // //other way to do the same thing
    // //auto keyword is generally not recommanded
    // for(auto value:s1){
    //     cout<<value<<" ";
    // }
    // cout<<endl;

    // //deletion in set
    // s1.erase(4);
    // for(itr=s1.begin();itr!=s1.end();itr++){
    //     cout<<*itr<<" ";
    // }
    // cout<<endl;

    // s1.insert(4);

    // auto itr1=s1.begin();
    // advance(itr1,2);
    // s1.erase(itr1);
    // for(itr=s1.begin();itr!=s1.end();itr++){
    //     cout<<*itr<<" ";
    // }
    // cout<<endl;


    // //for clearing a range of elements
    // auto start_itr=s1.begin();;
    // auto end_itr=s1.begin();
    // advance(end_itr,2);

    // s1.erase(start_itr,end_itr);

    // for(itr=s1.begin();itr!=s1.end();itr++){
    //     cout<<*itr<<" ";
    // }
    // cout<<endl;

    set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);

    for(auto i=set1.rbegin();i!=set1.rend();i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    for(auto i=set1.begin();i!=set1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    
    


    return 0;
}