#include<iostream>
using namespace std;

bool powerOf2(int n){
    return (n && !(n & n-1)); //if n & n-1 is 0 then ! will make it true and n && is because it should not be 0

}

int main(){
    int n;
    cin>>n;
    cout<<powerOf2(n)<<endl;//1 will mean true, 0 means false
    return 0;
}
