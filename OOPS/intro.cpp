#include<iostream>
using namespace std;

class hero{


    //properties
    private:
    int health;

    public:
    char name[100];
    char level;
    

    void getHealth(){//getter 
        cout<<health<<endl;
    }

    //setter
    void setHealth(int h){
        health=h;
    }

};

int main(){
    //static allocation
    hero a;
    //dynamic allocation
    hero *h=new hero;
    (*h).getHealth();
    h->getHealth();





    // hero h1;
    
    // h1.level='a';
    // h1.getHealth();
    // h1.setHealth(100);
    // h1.getHealth();
    // cout<<h1.level<<endl;
    return 0;
}