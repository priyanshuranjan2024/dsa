#include<bits/stdc++.h>
using namespace std;

class hero{


    //properties
    private:
    int health;

    public:
    char name[100];
    char level;


    static int  timeToComplete;

    
    //parameterised constructor

    hero(int health,char level){
        
        this->health=health;
        this->level=level;
    }

    // //copy constructor (manually created)
    // hero(hero& temp){
    //     this->health=temp.health;
    //     this->level=temp.level;
    // }

    void print(){
        cout<<this->health<<endl;
        cout<<this->level<<endl;
    }
    

    void getHealth(){//getter 
        cout<<health<<endl;
    }

    //setter
    void setHealth(int h){
        health=h;
    }
    //destructor class called

    ~hero(){
        cout<<"bye guys"<<endl;
    }



    

};

int hero::timeToComplete=5;

int main(){
    cout<<hero::timeToComplete<<endl;


















    // hero suresh(100,'a');
    // suresh.print();

    // hero ramesh(suresh);//copied all the values from suresh to ramesh
    // ramesh.print();

    // suresh.setHealth(80);

    // suresh.print();
    // ramesh.print();










    // // hero ramesh(100);//parameterised constructor
    // // ramesh.getHealth();

    // // // //static allocation
    // // // hero a;
    // // // //dynamic allocation
    // // // hero *h=new hero;
    // // // (*h).getHealth();
    // // // h->getHealth();





    // // // // hero h1;
    
    // // // // h1.level='a';
    // // // // h1.getHealth();
    // // // // h1.setHealth(100);
    // // // // h1.getHealth();
    // // // // cout<<h1.level<<endl;
    return 0;




}