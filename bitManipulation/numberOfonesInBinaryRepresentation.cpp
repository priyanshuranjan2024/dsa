#include<iostream>
using namespace std;
//for example n=19 n-1=18 then n & n-1 will be 18 so we will do this until n=0
int numberOfOnes(int n){
    int count=0;
    while(n){
        n=n & (n-1);
        count++;
    }
    return count;
}







int main(){
    int n;
    cin>>n;
    cout<<numberOfOnes(n)<<endl;
    return 0;
}