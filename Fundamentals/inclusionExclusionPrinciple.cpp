#include<iostream>
using namespace std;
//find total numbers which are divisble by 5 or 7 in range 1,n
int divisible(int n, int a, int b){
    int c1=n/a;//total number of numbers divisible by a
    int c2=n/b;
    int c3=n/(a*b);

    return c1+c2-c3;


}






int main(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<divisible(n,a,b);
    return 0;
}