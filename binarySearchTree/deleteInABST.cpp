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

Node* inOrderSucc(Node* root){
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }

    return curr;
}


//delete in BST
Node* deleteInBST(Node* root,int key){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=deleteInBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteInBST(root->right,key);
    }
    else{
        //firstly handle case 1 and case 2
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        //case 3
        Node* temp=inOrderSucc(root->right);
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data);

    }

    return root;

}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);

}



int main(){
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);

    inorderPrint(root);
    cout<<endl;

    root=deleteInBST(root,5);
    inorderPrint(root);


    return 0;
}