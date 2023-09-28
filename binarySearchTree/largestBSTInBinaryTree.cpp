#include<bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
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

//create another structure named Info
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
    
};

//main function 
Info largestBSTInBT(Node* root){
    //the info of root will contain our desired answer
    //base case 1 if root is null
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    //base case 2 if root is leave node
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }

    //now the main part
    //firstly i will collect info of left and right subtree
    Info leftInfo=largestBSTInBT(root->left);
    Info rightInfo=largestBSTInBT(root->right);

    //now initialise curr whose info we will return that is the curr root
    Info curr;
    curr.size=1+leftInfo.size+rightInfo.size;

    //check whether it is overall a bst or not
    if(leftInfo.isBST && rightInfo.isBST && root->data>leftInfo.max && root->data<rightInfo.min){
        //if all conditions are true then set the values curr info
        curr.min=min(leftInfo.min,min(rightInfo.min,root->data));
        curr.max=max(max(leftInfo.max,root->data),rightInfo.max);

        curr.ans=curr.size;
        curr.isBST=true;

        return  curr;
    }

    //if bst is not forming at current root
    curr.ans=max(leftInfo.ans,rightInfo.ans);
    curr.isBST=false;
    return curr;
}



int main(){
    Node* root=new Node(15);
    root->left=new Node(20);
    root->left->left=new Node(5);
    root->right=new Node(30);

    cout<<"Largest BST in BT size : "<<largestBSTInBT(root).ans<<endl;




    return 0;
}