#include<iostream>
using namespace std;
//find the number of ways in which n friends can remain single or  can be paired up
int friendsPairing(int n){
    //base case
    if(n==0 || n==1 || n==2){
        return n;
    }
    //recursive part
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1);//first case if we let the person single other is the one where we let them pair 

}



int main(){
    int n;
    cin>>n;
    cout<<friendsPairing(n)<<endl;
    return 0;
}