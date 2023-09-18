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


//to calculate the height we willl basically use the recursion and then add 1
int calHeight(Node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    int lHeight=calHeight(root->left);
    int rHeight=calHeight(root->right);

    return max(lHeight,rHeight)+1;

}




int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);


    cout<<calHeight(root)<<endl;


    return 0;
}