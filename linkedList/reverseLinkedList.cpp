#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* next=NULL;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void insertAtTail(node* &head,int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }

    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node * head){
    node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->"<<" ";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
}



//iterative way
node* reverseLinkedList(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;

        currptr->next=prevptr;
        

        prevptr=currptr;
        currptr=nextptr;

    }

    return prevptr;//new head

}


//recursive way
node* recursiveReverseLinkedList(node * &head){

    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }


    node* newhead=recursiveReverseLinkedList(head->next);//reverse every node except head

    head->next->next=head;
    head->next=NULL;

    return newhead;

}




int main(){
    node *head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    display(head);

    // node* newhead=reverseLinkedList(head);
    node* newhead=recursiveReverseLinkedList(head);
    
    display(newhead);
    return 0;
    
}