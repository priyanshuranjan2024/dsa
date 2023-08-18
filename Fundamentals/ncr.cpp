#include<iostream>
using namespace std;

int fac(int n){
    int factorial=1;
    if(n==0 || n==1){
        return 1;
    }
    
    else{
        for(int i=2;i<=n;i++){
            factorial=factorial*i;
        }
        return factorial;
    }
    

}




int main(){
    int n,r;
    cin>>n>>r;
    int n_fac=fac(n);
    int r_fac=fac(r);
    int nr_fac=fac(n-r);
    cout<<n_fac/(r_fac*nr_fac);
    return 0;
}