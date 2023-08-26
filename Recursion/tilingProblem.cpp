#include<iostream>
using namespace std;
//given a "2xn" board and tiles of size "2x1" , count the number of ways to tile the given  board using these tiles

int tilingWays(int n){
    //base cases
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return tilingWays(n-1)+tilingWays(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<tilingWays(n)<<endl;
    return 0;
}