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

//time complexity O(n)
//using height pointer
bool isBalancedReducedTimeComplexity(Node* root,int* height){

    //base condition
    if(root==NULL){
        return true;
    }

    int lh=0,rh=0;
    if(isBalancedReducedTimeComplexity(root->left,&lh)==false){
        return false;
    }
    if(isBalancedReducedTimeComplexity(root->right,&rh)==false){
        return false;
    }

    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;

    }
    else{
        return false;
    }

}




//time complexity O(n^2)
int height(Node* root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left),height(root->right))+1;
}


bool isBalanced(Node* root){

    //base condition leaf node is always balanced
    if(root==NULL){
        return true;
    }

    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}






int main(){

    //balanced tree

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    if(isBalanced(root)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }

    //unbalanced tree
    Node* root1=new Node(1);
    root1->left=new Node(2);
    root1->left->left=new Node(3);

    if(isBalanced(root1)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }
    


    int height=0;



    if(isBalancedReducedTimeComplexity(root,&height)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }

    

    height=0;

    if(isBalancedReducedTimeComplexity(root1,&height)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }

    


    return 0;
}