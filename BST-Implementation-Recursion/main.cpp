#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
public:
    Node *root;

    BinarySearchTree(){
        root = nullptr;
    }

    Node* insert(Node *root,int val){
        Node *newNode = new Node(val);

        if(root == nullptr)
            return newNode;

        if(val<root->data)
            root->left = insert(root->left,val);
        else
            root->right = insert(root->right,val);
        
        return root;
    }

    void inorder(Node *root){
        if(root!=nullptr){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void preorder(Node *root){
        if(root!=nullptr){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root){
        if(root!=nullptr){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }

};


int main(){

    BinarySearchTree bst;

    int val;

    do{
        cin>>val;
        if(val!=-1)
            bst.root = bst.insert(bst.root,val);
    }while(val!=-1);

    bst.inorder(bst.root);
    cout<<endl;
    bst.preorder(bst.root);
    cout<<endl;
    bst.postorder(bst.root);

    return 0;
}