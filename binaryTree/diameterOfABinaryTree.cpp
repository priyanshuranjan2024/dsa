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

// The diameter of a binary tree is defined as the length of the longest path between any two nodes
// in a tree. This path may or may not pass through the root.
// The length of a path is the number of edges on the path, not the number of nodes.
// To calculate the diameter of a binary tree, you can use a recursive approach. The diameter of a binary tree is the maximum of the following three quantities:
// Diameter of the left subtree.
// Diameter of the right subtree.
// Longest path between two nodes that goes through the root.
// This can be calculated as the sum of the heights of the left and right subtrees plus 1.



int calHeight(Node* root){
    //base condition
    if(root==NULL){
        return 0;
    }
    return max(calHeight(root->left),calHeight(root->right))+1;
}

int calDiameter(Node* root){
    if(root==NULL){
        return 0;
    }

    int lHeight=calHeight(root->left);
    int rHeight=calHeight(root->right);

    int currDiameter=lHeight+rHeight+1;

    int lDiameter=calDiameter(root->left);
    int rDiameter=calDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));

}




int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    // cout<<calDiameter(root,)<<endl;
    int height=0;
    cout<<calDiameter(root)<<endl;


    return 0;

}