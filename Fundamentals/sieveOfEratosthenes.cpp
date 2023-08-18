#include<iostream>
using namespace std;


void primeSieve(int n){
    int prime[100]={0};
    for(int i=2;i<=n;i++){
        //prime[i]==0 means it is unmarked and i have to mark its multiple
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;//marking the mulitiples
            }

        }
    }

    //printing the primes
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }

}

int main(){
    int n;
    cin>>n;
    primeSieve(n);
    return 0;
}