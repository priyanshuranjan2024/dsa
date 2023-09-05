#include<iostream>
using namespace std;

class base{
    public:
    virtual void func(){
        cout<<"hello Priyanshu Ranjan"<<endl;
    }
};

class derived:public base{
    public:
    void func(){
        cout<<"hello Priyanshu"<<endl;
    }
};


int main(){

    base *basestr;
    derived d;
    basestr=&d;
    basestr->func();
    return 0;

    
}