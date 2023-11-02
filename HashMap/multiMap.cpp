#include<bits/stdc++.h>
using namespace std;

int main(){

    multimap<string,int> directory;

    directory.insert(make_pair("Priya",12345));
    directory.insert(make_pair("Ranjana Singh",6789));
    directory.insert(make_pair("Ranjana Singh",1245789));//repeated key

    for(auto pair:directory){
        cout<<"Name  "<<pair.first<<endl;
        cout<<"Phone "<<pair.second<<endl;

        cout<<endl;

    }

    //note for multimap, [] operator to assign key-values is not allowed



    return 0;
}