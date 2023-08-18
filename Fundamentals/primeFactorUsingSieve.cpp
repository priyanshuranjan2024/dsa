#include<iostream>
using namespace std;

void primeFactor(int n){
    int spf[100]={0};//spf=smallest prime factor
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    //using same concept as sieve of eratosthenes with little changes

    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;//updating spf  of j to smallest prime factor of it
                }
            }
        }
    }

    //printing the prime factors

    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n]; 
    }



}





int main(){
    int n;//taking the number
    cin>>n;
    primeFactor(n);
    return 0;
}