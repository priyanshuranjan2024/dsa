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

int maxPathSumUtil(Node* root,int & ans){
    if(root==NULL){
        return 0;
    }
    
    //calculate left sum and right sum
    int leftSum=maxPathSumUtil(root->left,ans);
    int rightSum=maxPathSumUtil(root->right,ans);

    int nodeMax=max(  max(root->data,root->data+leftSum+rightSum),  max(root->data+leftSum,root->data+rightSum));


    //compare ans with nodeMax
    ans=max(ans,nodeMax);

    //return singlePathSum
    int singlePathSum=max(root->data,max(root->data+leftSum,root->data+rightSum));
    return singlePathSum;//this is value that is the maxPath through the root




}


int maxPathSum(Node* root){
    int ans=INT_MIN;
    maxPathSumUtil(root,ans);//stub function to compare ans with all 4 values as per the strategy

    return ans;
}




int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(5);

    cout<<maxPathSum(root)<<endl;



    return 0;

}