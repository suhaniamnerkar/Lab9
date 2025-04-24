#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findDepth(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
  
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int depth = findDepth(root);
    printf("Depth of the tree is: %d\n", depth);

    return 0;
}
