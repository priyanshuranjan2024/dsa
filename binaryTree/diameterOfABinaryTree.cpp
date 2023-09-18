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

// //to calculate the diameter we will calculate the max of maxHeight and maxDiameter

// int calHeight(Node* root){
//     //base condition
//     if(root==NULL){
//         return 0;
//     }
//     return max(calHeight(root->left),calHeight(root->right))+1;
// }

// int calDiameter(Node* root){
//     if(root==NULL){
//         return 0;
//     }

//     int lHeight=calHeight(root->left);
//     int rHeight=calHeight(root->right);

//     int currDiameter=lHeight+rHeight+1;

//     int lDiameter=calDiameter(root->left);
//     int rDiameter=calDiameter(root->right);

//     return max(currDiameter,max(lDiameter,rDiameter));

// }


//better approach
int calDiameter(Node* root,int* height){
    if(root==NULL){
        *height=0;
        return 0;//diameter

    }
    int lh=0;
    int rh=0;
    int lDiameter=calDiameter(root->left,&lh);
    int rDiameter=calDiameter(root->right,&rh);

    int currDiameter=lh+rh+1;

    *height=max(lh,rh)+1;

    return max(max(lDiameter,rDiameter),currDiameter);




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
    cout<<calDiameter(root,&height)<<endl;


    return 0;

}