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
        root=nullptr;
    }

    void insert(int val){
        Node *newNode = new Node(val);

        if(root==nullptr){
            root=newNode;
            return;
        }
        
        Node *temp = root;

        while(true){
            if(val<temp->data){
                if(temp->left==nullptr){
                    temp->left=newNode;
                    break;
                }
                temp=temp->left;
            }
            else{
                if(temp->right==nullptr){
                    temp->right=newNode;
                    break;
                }
                temp=temp->right;
            }
        }
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
            bst.insert(val);
    }while(val!=-1);
    bst.inorder(bst.root);
    cout<<"\n";
    bst.preorder(bst.root);
    cout<<"\n";
    bst.postorder(bst.root);
    return 0;
}