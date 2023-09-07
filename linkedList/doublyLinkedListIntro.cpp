#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* previous;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->previous=NULL;
    }

};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->previous=n;

    }

    head=n;  
}

void insertAtTail(node* &head,int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }


    node* n=new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
    n->previous=temp;

}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->previous=NULL;

    delete todelete;

}

void deleteNode(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;

    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }

    //now we are the node we want to delete
    temp->previous->next=temp->next;
    if(temp->next!=NULL){
        temp->next->previous=temp->previous;

    }
    

    delete temp;


}

void display(node* head){
    node* temp=head;


    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
    

}



int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    display(head);

    deleteNode(head,2);
    display(head);
    

    return 0;
}