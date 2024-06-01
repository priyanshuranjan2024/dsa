#include<bits/stdc++.h>
using namespace std;

//since if the signs are different then the MSB will be different  then 
//the XOR of the two numbers will return 1 that means the signs are different

int main(){
    int a,b;
    cin>>a>>b;
    if((a^b)<0){
        cout<<"Opposite signs"<<endl;
    }else{ 
        cout<<"Same signs"<<endl;
    }

    return 0;
}