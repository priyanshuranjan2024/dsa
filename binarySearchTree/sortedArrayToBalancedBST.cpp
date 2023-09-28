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

//the approach will look something like binary search
Node* sortedArrayToBalancedBST(int arr[],int start,int end){

    //base case
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    //creating the root from mid value of the array
    Node* root=new Node(arr[mid]);
    //call the function for left and right subtree
    root->left=sortedArrayToBalancedBST(arr,start,mid-1);
    root->right=sortedArrayToBalancedBST(arr,mid+1,end);

    return root;


}

void printPreorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}


int main(){
    int arr[]={10,20,30,40,50};
    Node* root=sortedArrayToBalancedBST(arr,0,4);

    printPreorder(root);


    return 0;
}