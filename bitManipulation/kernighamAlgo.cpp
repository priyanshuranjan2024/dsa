#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=0;
    while(n){
        n&=(n-1);
        count++;
    }

    cout<<count<<endl;

    return 0;
}