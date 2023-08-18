#include<iostream>
using namespace std;

int setBit(int n,int position){
    return (n | (1<<position));
}

int main(){
    cout<<setBit(5,1)<<endl;
    return 0;
}