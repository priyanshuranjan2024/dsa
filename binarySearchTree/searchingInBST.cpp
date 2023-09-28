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

//will return the pointer whose data is equal to key
Node* searchInBST(Node* root,int key){
    //base case
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return root;
    }

    if(root->data>key){
        return searchInBST(root->left,key);
    }

    return searchInBST(root->right,key);

}


int main(){
    Node* root=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right=new Node(5);
    root->right->right=new Node(6);


    if(searchInBST(root,10)==NULL){
        cout<<"key doesn't exit"<<endl;

    }
    else{
        cout<<"key exit"<<endl;
    }
    return 0;
}