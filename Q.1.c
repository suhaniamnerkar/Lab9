#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node*create_node(int data){
    struct node*nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=data;
    nnode->left=NULL;
    nnode->right=NULL;
    return nnode;
}

struct node*insert(struct node*root,int data){
    if(root==NULL){
        return create_node(data);
    }
    if(data<root->data){
        root->left=insert(root,data);
    }
    else{
        root->right=insert(root,data);
    }
    return root;
}

void inorder_display(struct node*root){
    if(root==NULL) return;
    inorder_display(root->left);
    printf("%d ",root->data);
    inorder_display(root->right);
    
}

int main(){
    struct node*root=NULL;
    root=insert(root,20);
    struct node*root1=root;
    root=insert(root,15);
    root=insert(root,37);
    root=insert(root,9);
    root=insert(root,13);
    root=insert(root,56);
    root=insert(root,41);

    inorder_display(root);

    return 0;
}
