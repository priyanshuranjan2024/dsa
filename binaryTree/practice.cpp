#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode* buildTree(vector<int> postorder,vector<int> inorder,int start,int end){
    static int idx=6;
    if(start>end)  return NULL;
    //otherwise create a node decrement the idx
    int curr=postorder[idx];
    idx--;
    
}




void printInorderTraversal(TreeNode* root){
    if(root==NULL)  return;

    printInorderTraversal(root->left);
    cout<<root->data<<" ";
    printInorderTraversal(root->right);
}





int main(){

    //generate the postorder and inorder array for the binary tree
    vector<int> postorder={4,5,2,6,7,3,1};
    vector<int> inorder={4,2,5,1,6,3,7};


    TreeNode* root=buildTree(postorder,inorder,0,6);
    
    //now print the inorderTraversal of the binary tree
    printInorderTraversal(root);

    

    return 0;
}