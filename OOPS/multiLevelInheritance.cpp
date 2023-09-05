#include<iostream>
using namespace std;


class A{
    public:
    void Afunc(){
        cout<<"Hello Guys I am A"<<endl;
    }

};

class B:public A{
    public:
    void Bfunc(){
        cout<<"Hello Friends I am B"<<endl;
    }

};

class C:public B{
    public:
    void Cfunc(){
        cout<<"Hello Friends I am C"<<endl;
    }
};


int main(){
    C c;
    c.Afunc();
    c.Bfunc();
    c.Cfunc();
    
    return 0;
}