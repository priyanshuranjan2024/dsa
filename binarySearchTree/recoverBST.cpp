#include<bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node* left;
    Node* right;
    public:
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }
};


//swap function for int*
void swap(int* a ,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//calcPointers() will be a function which will traverse the bst in inorder fashion and calculate the pointers position
void calcPointers(Node* root,Node** first,Node** mid,Node** last,Node** prev){
    if(root==NULL){
        return;
    }

    //call for the left subtree
    calcPointers(root->left,first,mid,last,prev);

    //check if increasing order is violated or not
    if(*prev && root->data < (*prev)->data){
        //check if it is violated for the first time or more than one time
        if(!*first){
            *first=*prev;
            *mid=root;

        }
        else{
            //case1
            *last=root;

        }

        


    }
    *prev=root;
    //now call for right subtree
    calcPointers(root->right,first,mid,last,prev);


}


void restoreBST(Node* root){

    //initialise 4 pointers
    Node* first,*mid,*last,*prev;//prev pointer is a temporary pointer
    //initialise all of them using  null
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;

    //call a utility function
    calcPointers(root,&first,&mid,&last,&prev);

    //case 1 first and last are not null swapping is done between non adjacent ones
    if(first && last){
        swap(&(first->data),&(last->data));
    }
    //case 2
    else if(first && mid){
        swap(&(first->data),&(mid->data));

    }

    


}

//inorder
void inorder(Node* root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}



int main(){

    //violatated bst
    Node* root=new Node(6);
    root->left=new Node(9);
    root->right=new Node(3);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->right=new Node(13);

    //print the inorder of violated bst
    inorder(root);
    cout<<endl;

    restoreBST(root);

    //restrored bst inorder
    inorder(root);
    cout<<endl;


    return 0;
}