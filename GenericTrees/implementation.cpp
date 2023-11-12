#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    char data;
    vector<Node*> children;//will contain the references to all children nodes 

    //constructor
    Node(char data){
        this->data=data;
    }

};



int main(){

    Node* root=new Node('A');
    root->children.push_back(new Node('B'));//this will push the child node in the vector children
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node('D'));

    cout<<root->data<<endl;//checking if the the node is correct

    //to traverse the the children node we can use for each loop
    for(Node* child:root->children){
        cout<<child->data<<" ";//child is the reference to the children node

    }
    cout<<endl;



    



    return 0;
}