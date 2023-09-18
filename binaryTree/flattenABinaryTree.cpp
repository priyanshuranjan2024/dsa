//problem
//givena binary tree,flattern it into  linked list in-place. After flattenign,lerft of each node should
// point to NULL and right should contain next node in preorder sequence.
//note it is not allowed to use  other data structure
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node*  left;
    Node* right;

    public:
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void flatten(struct Node* root){

    //base condition
    if(root==NULL ||(root->left==NULL && root->right==NULL)){
        return;
    }


    if(root->left!=NULL){
        flatten(root->left);

        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        //now traverse to the end of the right tail
        Node* t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }

        t->right=temp;


    }

    flatten(root->right);

}

//the inOrder of the linked list will be different from the original binary tree
void inOrderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);


}




int main(){
    Node* root=new Node(4);
    root->left=new Node(9);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);


    
    inOrderPrint(root);
    cout<<endl;


    flatten(root);
    
    inOrderPrint(root);
    cout<<endl;



    return 0;
}