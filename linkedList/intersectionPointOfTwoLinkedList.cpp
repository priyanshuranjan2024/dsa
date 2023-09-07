#include<C:\Users\KIIT0001\Desktop\Programming\cpp\linkedList\linkedListImpFunctions.cpp>
#include<iostream>
using namespace std;

void intersect(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    pos--;
    while (pos--)
    {
        temp1=temp1->next;
    }

    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }

    temp2->next=temp1;
    
}

int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }

    return l;
}

int intersection(node* &head1,node* &head2){

    int l1=length(head1);
    int l2=length(head2);

    int diff=0;

    node* ptr1;
    node* ptr2;

    if(l1>l2){
        diff=l1-l2;
        ptr1=head1;
        ptr2=head2;

    }
    else{
        diff=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(diff){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        diff--;


    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }

        ptr1=ptr1->next;
        ptr2=ptr2->next;

    }

    return -1;//if not found
    
}


int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);    
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    
    insertAtTail(head2,9);
    insertAtTail(head2,10);

    intersect(head1,head2,3);

    display(head1);
    display(head2);

    cout<<intersection(head1,head2);
    


    return 0;
}