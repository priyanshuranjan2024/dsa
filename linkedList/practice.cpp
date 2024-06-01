#include<bits/stdc++.h>
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

//insert at head function
void insertAtHead(node* &head,int val){
    node*  n=new node(val);
    n->next=head;
    head=n;
}


//insert at tail function

void insertAtTail(node* &head,int val){
    //create the new node
    node* n=new node(val);

    //what if the head is null
    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL) temp=temp->next;

    //now put the new node in the temp.next
    temp->next=n;
}


//display function
void display(node* &head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;

    }

    cout<<"NULL"<<endl;
}

//search function
bool search(node* &head,int key){
    node* temp=head;
    while(temp!=nullptr){
        if(temp->data==key) return true;
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
    if(head==nullptr) return;
    if(head->next==nullptr){
        toDeleteAtHead(head);
        return;
    }

    node* temp=head;
    while(temp->next->data!=val) temp=temp->next;
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

//iterative way to reverse the linked list
node* revereseLinkedList(node* &head){
    //create three pointers
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }

    return prevptr;
}

//recursive way to reverse the linked list
node* reverseLinkedListRecursive(node* &head){
    if(head==NULL || head->next==NULL) return head;
    node* newhead=reverseLinkedListRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

node* reverseKNodes(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;

    while(currptr!=NULL ||count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        //now update
        prevptr=currptr;
        currptr=nextptr;
        count++;
        
    }

    if(nextptr!=nullptr) head->next=reverseKNodes(nextptr,k);
    return prevptr;
    
}

int main(){
    node* Link=new node(1);
    insertAtTail(Link,2);
    insertAtHead(Link,3);

    display(Link);

    if(search(Link,2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    node* reverse=revereseLinkedList(Link);
    display(reverse);

    node* reverseRecursive=reverseLinkedListRecursive(Link);

    display(reverse);


    


    return 0;
}