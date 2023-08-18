#include<iostream>
using namespace std;

int updateBit(int n,int position,int value){
    //clearing the bit at the specified position first
    n=(n & (~(1<<position)));
    return (n | (value<<position));


}





int main(){
    cout<<updateBit(5,1,1)<<endl;
    return 0;
}