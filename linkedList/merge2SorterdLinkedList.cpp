#include<C:\Users\KIIT0001\Desktop\Programming\cpp\linkedList\linkedListImpFunctions.cpp>


//iterative way
node* merge(node* head1,node* head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;

        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }

    while (p2!=NULL)
    {
        p3=p3->next;
        p2=p2->next;
        p3=p3->next;

    }

    return dummyNode->next;
    

}


//recursive way
node* mergeRecursive(node* &head1,node* &head2){

    //base case is if elements of one linked list is exhausted
    if(head1==NULL){
        return head2;
    }

    if(head2==NULL){
        return head2;
    }


    //firstly create a result pointer
    node* result;
    //now we will check whether data in head1 is greater than head2 data if yes we will result=head1
    //and call the function again for result->next
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }

    return result;

    
}



int main(){

    node* head1=NULL;
    node* head2=NULL;

    int arr1[]={1,4,5,7};
    int arr2[]={2,3,6};
    for(int i=0;i<4;i++){
        insertAtTail(head1,arr1[i]);
    }

    for(int i=0;i<3;i++){
        insertAtTail(head2,arr2[i]);
    }

    // node* newHead=merge(head1,head2);
    node * newHead=mergeRecursive(head1,head2);

    display(newHead);

    return 0;

}