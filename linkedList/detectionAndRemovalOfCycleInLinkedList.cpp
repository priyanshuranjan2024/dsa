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

void insertAtTail(node* &head,int val){
    node* n=new node(val);
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
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;

}

void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startNode;//the pointer to which we will link the last node to make cycle

    int count=1;

    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;//where to link the  last node to
        }

        temp=temp->next;
        count++;

    }

    //after coming out of while loop temp is on the last node
    temp->next=startNode;

    
    
}


bool detectCycle(node* &head){
    //hare and tortoise algorithm
    node* tortoise=head;
    node* hare=head;

    while(hare!=NULL && hare->next!=NULL){
        tortoise=tortoise->next;
        hare=hare->next->next;

        if(hare==tortoise){
            return true;
        }
    }

    return false;

}

void removeCycle(node*  &head){

    //after meeting hare will be assigned to head again and then both pointer will be 
    //forwared +1 until there next are equal then we will 
    //make tortoise next assigned to null
    node* tortoise=head;
    node* hare=head;

    do
    {
        tortoise=tortoise->next;
        hare=hare->next->next;

    } while (tortoise!=hare);

    hare=head;
    while(tortoise->next!=hare->next){
        tortoise=tortoise->next;
        hare=hare->next;
    }

    tortoise->next=NULL;
    

}


int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    makeCycle(head,3);
    // display(head);

    cout<<detectCycle(head)<<endl;

    removeCycle(head);

    cout<<detectCycle(head)<<endl;


    

    return  0;
}