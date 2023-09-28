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


Node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n){


    //it is the base condition
    if(*preorderIdx>=n){
        return NULL;
    }


    //create the root node which you will return
    Node* root=NULL;



    //check if it is valid for being bst
    if(key>min && key<max){
        root=new Node(key);
        *preorderIdx+=1;//increasing the pointer by one

        //creating the left subtree
        if(*preorderIdx<n){
            root->left=constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }


        //creating the right subtree
        if(*preorderIdx<n){
            root->right=constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }

    }



    //else return the root
    return root;


}

void printPreorder(Node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);

}

int main(){

    int preorder[]={10,2,1,13,11};
    int n=5;
    int preorderIdx=0;
    Node* root=constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    
    printPreorder(root);



    return 0;
}