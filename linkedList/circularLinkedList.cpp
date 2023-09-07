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

void insertAtHead(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;//for traversing to the last 

    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next=n;
    n->next=head;

    head=n;

}

void insertAtTail(node* &head,int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;

    while(temp->next!=head){//will help us to traverse to the last node of circular linked list
        temp=temp->next;
    }

    temp->next=n;
    n->next=head;

}

void deletionAtHead(node* &head){
    node* temp=head;
    //traversing to the last element in circular linked list
    while(temp->next!=head){
        temp=temp->next;

    }

    node* todelete=head;
    temp->next=head->next;
    head=head->next;

    delete todelete;

    
}

void deletion(node* &head,int pos){
    if(pos==1){
        deletionAtHead(head);
        return;

    }


    node* temp=head;
    int count=1;

    while(count!=pos-1){
        temp=temp->next;
        count++;
    }

    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
    
}

void display(node* head){
    node* temp=head;

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);

    cout<<endl;
    
}





int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    display(head);

    insertAtHead(head,5);

    display(head);

    deletion(head,5);
    display(head);

    deletionAtHead(head);
    display(head);




    return 0;
}