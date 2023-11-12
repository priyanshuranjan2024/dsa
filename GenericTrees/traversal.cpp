#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    vector<Node*> children;

    Node(char data){
        this->data=data;
    }

};

//preorder traversal
void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    for(Node* child:root->children){
        preOrderTraversal(child);
    }

    return;
}

void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    int childNodes=root->children.size();

    //call the tarversal for firstly all childrens except the last element
    for(int i=0;i<childNodes-1;i++){
        inOrderTraversal(root->children[i]);
    }
    //print the root element
    cout<<root->data<<" ";

    if(childNodes>0){
        inOrderTraversal(root->children[childNodes-1]);//calling for the last child
    }

    return;


}


void postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    //firstly  call for each child node

    for(Node* child:root->children){
        postOrderTraversal(child);
    }

    //finally print the root node

    cout<<root->data<<" ";

    return ;
}


void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;//to push the node and then its children levelwise
    //now push the root first
    q.push(root);

    while(!q.empty()){
        int currSizeAtTheLevel=q.size();
        //now run a while loop till the size of the current level and pop and add their children
        while(currSizeAtTheLevel--){
            Node* curr=q.front();
            q.pop();
            cout<<curr->data<<" ";

            //now add its child nodes in the queue
            for(Node* child:curr->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
}



int main(){

    Node* root=new Node('A');
    root->children.push_back(new Node('B'));//this will push the child node in the vector children
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node('D'));

    root->children[0]->children.push_back(new Node('E'));
    root->children[0]->children.push_back(new Node('F'));
    
    root->children[2]->children.push_back(new Node('G'));

    preOrderTraversal(root);
    cout<<endl;

    inOrderTraversal(root);
    cout<<endl;

    postOrderTraversal(root);
    cout<<endl;

    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}