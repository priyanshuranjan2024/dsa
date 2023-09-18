#include<bits/stdc++.h>
using namespace std;

struct Node{
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

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }

    return -1;

}

Node* buildTree(int preorder[],int inorder[],int start,int end){
    //where start and end is the starting and ending index of the inorder[]
    static int idx=0;//idx for preorder[]

    if(start>end){
        return NULL;
    }

    int curr=preorder[idx];
    idx++;

    Node* node=new Node(curr);

    if(start==end){
        return node;
    }

    int pos=search(inorder,start,end,curr);//will check the the position of the curr in inorder[]

    node->left=buildTree(preorder,inorder,start,pos-1);
    node->right=buildTree(preorder,inorder,pos+1,end);

    return node;

}

void inOrderPrint(Node* root){

    if(root==NULL){
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);

}



int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    Node* root=buildTree(preorder,inorder,0,4);

    inOrderPrint(root);

    return 0;
}