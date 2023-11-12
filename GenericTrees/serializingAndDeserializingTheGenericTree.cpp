#include<bits/stdc++.h>
using namespace std;



//Serialize and Deserialize an N-ary tree. 

// Serialization is the process of converting an object into a format that can be stored or transmitted.

// Deserialization is the process of converting the serialized string back into an object.

// Serialization is to store tree in a file so that it can be later restored. The structure of tree must be maintained. 
// Deserialization is reading tree back from file.

class Node{
    public:
    int data;

    vector<Node*> children;
    Node(int data){
        this->data=data;
    }

};

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

void serialise(Node* root,string &ans){
    if(root==NULL){
        return;
    }

    //firstly convert root into string
    ans+=to_string(root->data)+":"+to_string(root->children.size())+":";
    //now add all its children data
    for(Node* child:root->children){
        ans+=to_string(child->data)+",";

    }
    //remove the last comma and replace it with newline character
    if(root->children.size()) ans.pop_back();//so that we have : in case of leaf node at the end
    ans+="\n";
    //now call it recursively
    for(Node* child:root->children){
        serialise(child,ans);

    }
}

Node* deseiralise(string ans){
    if(ans==""){
        return NULL;
    }

    //create map
    unordered_map<int,string> mp;//nodevalue,childNodeString
    for(int i=0;i<ans.size();i++){
        //creating the map
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

    string ans="";
    serialise(root,ans);
    cout<<ans;

    //now deserialize root
    Node* deserislized_root=deseiralise(ans);
    levelOrderTraversal(deserislized_root);
    
    return 0;
}

//serialised string
// 10:4:2,34,56,100
// 2:0
// 34:1:1
// 1:0
// 56:0
// 100:3:7,8,9
// 7:0
// 8:0
// 9:0