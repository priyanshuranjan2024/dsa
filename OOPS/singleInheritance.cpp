#include<iostream>
using namespace std;


class A{
    public:
    void func(){
        cout<<"Hello World"<<endl;
    }

};

class B:public A{
    //inherited from A
};

int main(){

    B bro;
    bro.func();
    
    return 0;
}