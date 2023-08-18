#include<iostream>
using namespace std;

void fac(int n){
    int factorial=1;
    if(n==0 || n==1){
        cout<<"1";
    }
    
    else{
        for(int i=2;i<=n;i++){
            factorial=factorial*i;
        }
        cout<<factorial;
    }
    return;
}


int main(){
    int n;
    cin>>n;
    fac(n);
    return 0; 
}