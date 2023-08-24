#include<iostream>
using namespace std;

//calculate the sum till n
//we can also write it as sum=n+n-1+n-2+...
//or we can write it as sum=n+sum till n-1
int Sum(int n){
    if(n==0){
        return 0;
    }
    int preSum=Sum(n-1);
    return n+preSum;
}

int main(){
    int n;
    cin>>n;
    cout<<Sum(n)<<endl;
    return 0;
}