#include<iostream>
using namespace std;
void swap_numbers(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a=2;
    int b=4;
    swap_numbers(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}