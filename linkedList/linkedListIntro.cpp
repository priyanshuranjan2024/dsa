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

void insertAtHead(node* &head,int val){
    node *n=new node(val);
    n->next=head;
    head=n;
}

//function to insert new node at the end of the linked list
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


bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }

    return false;
}


void toDeleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;
}



void toDelete(node* &head,int val){
    //if linked list is empty
    if(head==NULL){
        return;
    }
    //if linked list contain only one node
    if(head->next=NULL){
        toDeleteAtHead(head);
        return;

    }
    //val is the the node to be deleted
    node* temp=head;

    
    while(temp->next->data!=val){
        temp=temp->next;
    }

    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;

}




int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);

    insertAtHead(head,4);
    display(head);

    cout<<search(head,5)<<endl;
    cout<<search(head,3)<<endl;

    // toDelete(head,3);
    toDeleteAtHead(head);

    display(head);


    return  0;
}