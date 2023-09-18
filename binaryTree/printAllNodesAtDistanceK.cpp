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

//case 1 search in the node's subtree
void printSubTreeNodes(Node* root,int k){
    if(root==NULL || k<0){
        return;//since no possible answer
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printSubTreeNodes(root->left,k-1);
    printSubTreeNodes(root->right,k-1);

}

//case 2
int printNodesAtK(Node* root,Node* target,int k){
    if(root==NULL){
        return -1;//this will mean that it is not possible 
    }

    if(root==target){
        printSubTreeNodes(root,k);
        return 0;//this is because we have found the target is equal to root

    }

    int dl=printNodesAtK(root->left,target,k);//for left subtree
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";

        }
        else{
            printSubTreeNodes(root->right,k-dl-2);
        }

        return dl+1;
    }

    //for right subtree case where we find the target
    int dr=printNodesAtK(root->right,target,k);//for left subtree
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";

        }
        else{
            printSubTreeNodes(root->left,k-dr-2);
        }

        return dr+1;
    }

    //if we could not find the target node in any subtree and root is also not equal to the target
    return -1;


}


int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);

    printNodesAtK(root,root->left,1);
    return 0;

    return 0;
}