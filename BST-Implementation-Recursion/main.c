#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node* insert(struct Node *root,int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right =NULL;

    if(root==NULL)
        return newNode;
    
    if(val<root->data)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right,val);
    
    return root;
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){

    int val;

    do{
        scanf("%d",&val);
        if(val!=-1)
            root = insert(root,val);
    }while(val!=-1);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}