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




void zigzagTraversal(Node* root){
    //base case
    if(root==NULL){
        return;
    }


    //creating two stacks
    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight=true;

    currLevel.push(root);

    while(!currLevel.empty()){
        Node* temp=currLevel.top();
        currLevel.pop();

        if(temp){
            //if not null
            cout<<temp->data<<" ";
            //now pushing its child in nextLevel stack

            //case 1 left to right
            if(leftToRight){
                if(temp->left){
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }

            //case 2 right to left

            else{
                if(temp->right){
                    nextLevel.push(temp->right);

                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }

        

        }
        //check if the currLevel is empty or not if empty then change the value of leftToRight for nextLevel and swap nextLevel and currLevel
        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel); 
        }
    }
}




int main(){

    Node*  root=new Node(12);
    root->left=new Node(9);
    root->right=new Node(15);
    root->left->left=new Node(5);
    root->left->right=new Node(10);

    zigzagTraversal(root);



    return 0;
}

//output 12 15 9 5 10 