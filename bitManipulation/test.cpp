#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int rightMost=n&(-n);
    cout<<rightMost<<endl;

    return 0;
}