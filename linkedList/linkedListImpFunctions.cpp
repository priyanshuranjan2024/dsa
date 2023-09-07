#include<iostream>
using namespace std;

class node{
    public:
    int data;//data field
    node* next;//stores the memory address of the next node

    //creating the constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }


};

void insertAtTail(node* &head ,int val){
    //creating new node and storing its value in a new pointer
    node* n=new node(val);

    //in case head's address is null
    if(head==NULL){
        head=n;
        return;
    }

    
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }

    temp->next=n;


}


void display(node* head){
    node* temp=head;//for traversing
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
}
