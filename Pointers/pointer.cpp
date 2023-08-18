#include<iostream>
using namespace std;
int main(){
    // int a=123;
    // int *aptr;
    // aptr=&a;
    // cout<<aptr<<endl;//prints  the memory address of variable a
    // cout<<*aptr<<endl;//prints the value stored in variable a
    // cout<<&aptr<<endl;//prints the memory address of variable a
    
    // //array and pointers
    // int arr[3]={10,20,30};
    // for(int i=0;i<3;i++){
    //     cout<<*(arr+i)<<" ";//or  use a separate pointer variable using *ptr=arr;
         
    // }

    //pointer to pointer
    int a=10;
    int *p=&a;
    int **q=&p;
    cout<<*p<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;
    
    return 0;
}