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

//we will return a vector with all the roots of possible bsts
vector<Node*> consrtructTrees(int start,int end){
    //where start will be 1 and end will be n
    vector<Node*> trees;

    //base case
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }


    for(int i=start;i<=end;i++){
        //construct leftSubtree and rightSubtree for bigger numbers
        vector<Node*> leftSubtree=consrtructTrees(start,i-1);//because in left subtree all values are less than root->data
        vector<Node*> rightSubtree=consrtructTrees(i+1,end);


        //now use the concept of catalan number
        for(int j=0;j<leftSubtree.size();j++){
            Node* left=leftSubtree[j];
            for(int k=0;k<rightSubtree.size();k++){
                Node*  right=rightSubtree[k];

                //now construct the actual node for i
                Node* node=new Node(i);
                node->left=left;
                node->right=right;

                trees.push_back(node);
            }
        }

        

    }

    return trees;

}

void preorderPrint(Node* root){

    if(root==NULL){
        return;
    }


    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);

}


int main(){
    vector<Node*> totalTrees=consrtructTrees(1,3);
    for(int i=0;i<totalTrees.size();i++){
        
        cout<<i+1<<" : ";


        preorderPrint(totalTrees[i]);

        cout<<endl;
    }
    
    return 0;
}