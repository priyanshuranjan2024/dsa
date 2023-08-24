#include<iostream>
using namespace std;
//calculate the factorial of a number n recursivly
int factorial(int n){
    if(n==0){
        return 1;
    }
    int prevFac=factorial(n-1);
    return n*prevFac;
}


int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}