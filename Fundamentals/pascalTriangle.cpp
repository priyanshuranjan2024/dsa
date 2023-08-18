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
int ncr(int a,int b){
    int n_fac=fac(a);
    int r_fac=fac(b);
    int nr_fac=fac(a-b);
    return n_fac/(r_fac*nr_fac);
    
}



int main(){
    int row;
    cin>>row;
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            cout<<ncr(i,j)<<" ";

        }
        cout<<endl;
    }
}