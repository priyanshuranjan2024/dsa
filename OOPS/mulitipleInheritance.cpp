#include<iostream>
using namespace std;


class A{
    public:
    void Afunc(){
        cout<<"Hello Friends"<<endl;
    }
};

class B{
    public:
    void Bfunc(){
        cout<<"Hello Friends :)"<<endl;
    }
};

//multiple inhertitance
class C:public A,public B{
    public:
};





int main(){
    C c;
    c.Afunc();
    c.Bfunc();
    
    return 0;
}