#include<bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node*  left;
    Node* right;
    public:
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

//isIdentical
bool isIdentical(Node* root1,Node* root2){
    //both roots are null
    if(root1==NULL && root2==NULL){
        return true;
    }
    //any one is null that means they are not structurally identical
    else if(root1==NULL || root2==NULL){
        return false;
    }
    //both roots are not null
    else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdentical(root1->left,root2->left);
        bool cond3=isIdentical(root1->right,root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }

        return false;
    }
}


int main(){
    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(3);

    if(isIdentical(root1,root1)){
        cout<<"Identical"<<endl;
    }
    else{
        cout<<"Not identical"<<endl;
    }

    Node* root2=new Node(6);
    root2->left=new Node(3);
    root2->right=new Node(10);

    if(isIdentical(root1,root2)){
        cout<<"Identical"<<endl;
    }
    else{
        cout<<"Not identical"<<endl;
    }

    

    return 0;
}