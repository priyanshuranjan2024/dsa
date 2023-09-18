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




int main(){

    return 0;
}