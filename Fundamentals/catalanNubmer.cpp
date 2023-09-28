#include<iostream>
using namespace std;


//return the nth catalan number
int catalan(int n){

    //base case when n=1 or n=0
    if(n<=1){
        return 1;
    }

    int res=0;//wil return this

    for(int i=0;i<n;i++){
        res+=catalan(i)*catalan(n-i-1);


    }

    return res;
}


int main(){
    for(int i=0;i<=10;i++){
        cout<<catalan(i)<<" ";
    }
    return 0;
}