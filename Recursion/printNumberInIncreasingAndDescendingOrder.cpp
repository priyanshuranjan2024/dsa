#include<iostream>
using namespace  std;
//print the numbers till n in 1.decreasing 2.increasing 
void decres(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    decres(n-1);
}


void incres(int n){
    if(n==0){
        return;
    }
    incres(n-1);
    cout<<n<<endl;
}



int main(){
    int n;
    cin>>n;

    decres(n);
    incres(n);
    
    return 0;
}