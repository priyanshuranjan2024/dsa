#include<linkedList\linkedListImpFunctions.cpp>

void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;

    while(odd->next!=NULL && even->next!=NULL){

        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;
    //in case linked list size is odd
    if(odd->next==NULL){
        even->next=NULL;
    }


}


int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    display(head);

    evenAfterOdd(head);

    display(head);

    return 0;
}