#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    
    int data;
    vector<Node*> children;

    Node(int data){
        this->data=data;
    }

};

//Given a Tree where every node contains a variable number of children, convert the tree to its mirror.

void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    //use a queue
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int currSizeOfTheLevel=q.size();
        while(currSizeOfTheLevel--){
            Node* curr=q.front();
            q.pop();
            cout<<curr->data<<" ";

            for(Node*  child:curr->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
}

void mirrorTree(Node* root){
    if(root==NULL){
        return;
    }
    //if root->children.size()<2 then also return
    if(root->children.size()<2){
        return ;
    }

    //now reverse the children vector
    reverse(root->children.begin(),root->children.end());
    //now call the mirrorTree() function recursively for each node in the array
    for(Node* child: root->children){
        mirrorTree(child);
    }
}



int main(){
    Node* root=new Node(10);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(56));
    root->children.push_back(new Node(100));
    root->children[1]->children.push_back(new Node(1));
    root->children[3]->children.push_back(new Node(7));
    root->children[3]->children.push_back(new Node(8));
    root->children[3]->children.push_back(new Node(9));

    //do level order traversal
    levelOrderTraversal(root);

    mirrorTree(root);
    levelOrderTraversal(root);


    
    

    return 0;
}