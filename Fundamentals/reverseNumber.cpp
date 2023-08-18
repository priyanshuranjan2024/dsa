#include<iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int reverse=0;
    while(num>0){
        int lastNumber=num%10;
        reverse=reverse*10+lastNumber;
        num=num/10;

    }
    cout<<reverse;

    







    return 0;

}