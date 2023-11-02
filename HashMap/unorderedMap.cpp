#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int,string> record;
    //rollno ,name

    record.insert(make_pair(1,"ria"));
    record.insert(make_pair(2,"nitin"));
    record[3]="priya";

    //for printing it or traversing it
    //we use for each loop
    for(auto pair:record){
        cout<<"Roll NO- "<<pair.first<<endl;
        cout<<"Name- "<<pair.second<<endl;
        cout<<endl;

    }//will be printed in random order
    
    
    return 0;
}