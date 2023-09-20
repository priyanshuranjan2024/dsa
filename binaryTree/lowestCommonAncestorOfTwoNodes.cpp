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


bool getPath(Node* root,int key,vector<int> &path){
    //base case
    if(root==NULL){
        return false;
    }
    //firstly we will assume that the element is in path if not the we will later remove that
    path.push_back(root->data);

    if(root->data==key){
        return true;
    }
    
    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }

    //if not found in the root nor in left subtree nor the right subtree 
    path.pop_back();
    return false;



}

int LCA(Node* root,int n1,int n2){

    //create two vector to store the the path
    vector<int> path1,path2;

    //check whether path exist or not if exit store the path else don't store it
    if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
        return -1;//not possible
    }

    int pathChange;//calculate the path change
    for(pathChange=0;pathChange< path1.size() && path2.size();pathChange++){
        if(path1[pathChange]!=path2[pathChange]){
            break;//pathChange found
        }

    }

    return path1[pathChange-1];
}


//more better approach
Node* LCA2(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* leftLCA=LCA2(root->left,n1,n2);
    Node* rightLCA=LCA2(root->right,n1,n2);

    if(leftLCA && rightLCA){
        //if they both are not null
        return root;
    }

    if(leftLCA!=NULL){
        return leftLCA;

    }

    return rightLCA;



}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->right=new Node(3);
    root->right->left=new Node(5);
    root->right->left->left=new Node(7);
    root->right->right=new Node(6);

    int n1=7;
    int n2=6;

    int lca=LCA(root,n1,n2);
    if(lca==-1){
        cout<<"LCA doesn't exit"<<endl;
        return 0;
    }

    cout<<lca<<endl;

    Node* lca2=LCA2(root,n1,n2);
    cout<<lca2->data<<endl;
    

    return 0;
}