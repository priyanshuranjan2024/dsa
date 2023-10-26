#include<bits/stdc++.h>
using namespace std;





int main(){
    map<string,int> directory;//initialsing the map
    
    //one way to insert elements  in the map
    directory.insert(make_pair("Priya",1234));

    //second way to insert elements in the map
    directory["Manisha"]=56789;

    //if key is already present then the value will be updated

    directory.insert(make_pair("Princy",13579));

    //for printing the elements
    //use for each loop
    for(auto element:directory){
        cout<<"Key "<<element.first<<endl;
        cout<<"Value "<<element.second<<endl;

    }

    cout<<endl;


    //to define an iterator we firstly declare the stl container for which we want our iterator to be
    map<string,int>::iterator itr;//name of the iterator is itr
    //now printing the elements of the direcotry using m.begin() and m.end()
    for(itr=directory.begin();itr!=directory.end();itr++){
        cout<<itr->first<<" ";
        cout<<itr->second<<" ";
        cout<<endl;
    }

    cout<<endl;

    map<string,int>::reverse_iterator ritr;

    //now using rbegin() and rend()
    for(ritr=directory.rbegin();ritr!=directory.rend();ritr++){
        cout<<ritr->first<<" ";
        cout<<ritr->second<<" ";
        cout<<endl;
    }

    cout<<endl;

    return 0;

}