#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

};

class queue{
    node* front;
    node* back;

    public:
    queue(){
        front=NULL;
        back=NULL;
    }

    void push(int x){
        //firstly create a node
        node* n=new node(x);
        //if no queue exited before
        if(front==NULL){
            back=n;
            front=n;
            return; 
        }
        back->next=n;
        back=n;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue underflows"<<endl;
            return;
        }

        node* todelete=front;
        front=front->next;
        delete todelete;


    }


    int peek(){
        if(front==NULL){
            cout<<"Queue underlow "<<endl;
            return -1;
        }

        return front->data;
    }

    bool empty(){
        if(front==NULL){
            return true;
        }
        
        return false;
    }

};


int main(){
    queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.peek()<<endl;

    q.pop();

    cout<<q.empty()<<endl;

    cout<<q.peek()<<endl;




    return 0;
}