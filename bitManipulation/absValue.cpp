#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int mask=(n>>31);
    cout<<mask<<endl;//this will return -1 if n is negative and 0 if n is positive
    //returning the absolute value of n
    int absValue=(n+mask)^mask;
    cout<<absValue<<endl;

    return 0;
}