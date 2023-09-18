#include<bits/stdc++.h>
using namespace std;

struct Node
{
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


void sumReplace(Node* root){
    //base condition
    if(root==NULL){
        return;
    }


    sumReplace(root->left);//calling for the left subtree
    sumReplace(root->right);//calling for the right subtree


    if(root->left!=NULL){
        root->data+=root->left->data;
    }

    if(root->right!=NULL){
        root->data+=root->right->data;
    }

}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    preOrder(root);
    cout<<endl;

    sumReplace(root);

    preOrder(root);
    cout<<endl;



    return 0;
}