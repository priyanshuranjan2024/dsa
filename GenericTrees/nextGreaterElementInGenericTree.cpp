#include<bits/stdc++.h>
using namespace std;

//Given a generic tree and an integer x. Find and return the node with the next larger element in the tree i.e. 
// find a node just greater than x. Return NULL if no node is present with value greater than x. 


//just check for every node if current node->data > x and it is less than answer node


class Node{
    public:
    int data;
    vector<Node*> children;

    Node(int data){
        this->data=data;
    }

};

void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    for(Node* child:root->children){
        preOrderTraversal(child);
    }


   
}

void justGreaterElement(Node* root,int x,Node* &ans){
    if(root==NULL){
        return ;
    }

    //else check the condition for root first
    if(root->data>x && (ans==NULL|| root->data<ans->data)){
        ans=root;
    }

    //now check all the child nodes recursively using for each loop
    for(Node* child:root->children){
        justGreaterElement(child,x,ans);//ans is by reference because we will update the same ans every time 
        //we call the justGreaterElemnet() function
    }

}


int main(){

    Node* root=new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));

    preOrderTraversal(root);
    cout<<endl;


    //now the main question
    int x=10;
    Node* ans=NULL;
    justGreaterElement(root,x,ans);//12


    if(ans==NULL){
        cout<<"NULL"<<endl;
    }
    else{
        cout<<ans->data<<endl;
    }


    return 0;
}