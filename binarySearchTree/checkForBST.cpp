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

bool isBST(Node* root,Node* min=NULL,Node* max=NULL){

    //base condition when root is NULL
    if(root==NULL){
        return true;
    }


    //check if root->data is less than or equal to min and root->data is greater than or equal to max
    if(min!=NULL && root->data<=min->data){
        return false;
    }

    if(max!=NULL && root->data>=max->data){
        return false;
    }

    //now if above condition are true then call the function for left subtree and right subtree
    bool leftValid=isBST(root->left,min,root);
    bool rightValid=isBST(root->right,root,max);

    return leftValid and rightValid;


}


int main(){
    Node* root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);

    if(isBST(root1,NULL,NULL)){
        cout<<"Valid BST"<<endl;
    }
    else{
        cout<<"Invalid BST"<<endl;
    }

    //second tree
    Node* root2=new Node(5);
    root2->left=new Node(2);
    root2->right=new Node(8);

    if(isBST(root2,NULL,NULL)){
        cout<<"Valid BST"<<endl;
    }
    else{
        cout<<"Invalid BST"<<endl;
    }



    return 0;
}