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

int sumAtK(Node* root,int K){
    if(root==NULL){
        return -1;//considering there is no negative element in the binary tree
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;

    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==K){
                sum+=node->data;
            }
            if(node->left){
                //if it is not NULL
                q.push(node->left);
                
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }

    return sum;
}




int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<sumAtK(root,2)<<endl;


    return 0;
}