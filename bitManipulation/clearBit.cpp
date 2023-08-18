#include<iostream>
using namespace std;

int clearBit(int n,int  position){
    return (n & (~(1<<position)));
}

int main(){
    cout<<clearBit(5,2)<<endl;
    return 0;
}