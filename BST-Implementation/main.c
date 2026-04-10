#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

void insert(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if(root==NULL){
        root = newNode;
        return;
    }

    struct Node *temp = root;
    while(1){
        if(val<temp->data){
            if(temp->left==NULL){
                temp->left = newNode;
                break;
            }
            temp=temp->left;
        }
        else{
            if(temp->right==NULL){
                temp->right=newNode;
                break;
            }
            temp=temp->right;
        }
    }
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
            insert(val);
    }while(val!=-1);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}