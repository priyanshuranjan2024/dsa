#include<iostream>
using namespace std;

class Complex{
    private:
    int real,img;
    public:
    //constructor
    Complex(int r,int img){
        this->real=r;
        this->img=img;

    }

    Complex operator +(Complex const &obj){
        Complex res;
        res.img=img+obj.img;
        res.real=real+obj.real;
        return res;
    }

    void display(){
        cout<<real<<"+ i"<<img<<endl;
    }


};


int main(){
    Complex c1(6,7),c2(2,3);
    Complex c3=c1+c2;
    c3.display();
    return 0;
}