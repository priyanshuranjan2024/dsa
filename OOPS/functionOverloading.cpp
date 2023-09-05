#include<iostream>
using namespace std;


class A{
    public:
    void func(){
        cout<<"I am a function with no arguments"<<endl;
    }
    void func(int a){
        cout<<"I am a function with int arguments"<<endl;

    }
    void func(double b){
        cout<<"I am a function with double  arguement"<<endl;
    }

};


int  main(){
    A a;
    a.func();
    a.func(1);
    a.func(1.6);
    return 0;
}