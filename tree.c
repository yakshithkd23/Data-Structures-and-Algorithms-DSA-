#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node* createNode(int data);
Node* buildTree(int *arr, int *index, int size);
void preorderTraversal(Node* root); 
void inorderTraversal(Node* root);
void postorderTraversal(Node* root);
int main() {
    int arr[] = {1, 2, 4, -1,-1, 5, -1, -1, 3, -1, 6, -1, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = 0;

    Node* root = buildTree(arr, &index, size);

    printf("Preorder traversal of the tree: ");
    preorderTraversal(root);
    printf("\ninorder transvarsal of the tree:");
    inorderTraversal(root);
    printf("\npostorder Traversal of the tree:");
    postorderTraversal(root);

    return 0;
}
Node* createNode(int data) {
    if (data == -1) {
        return NULL; // Return NULL for -1 input
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* buildTree(int *arr, int *index, int size) {
    if (*index >= size) {
        return NULL;
    }

    int data = arr[*index];
    (*index)++;
    if (data == -1) {
        return NULL;
    }

    Node* root = createNode(data);
    root->left = buildTree(arr, index, size);
    root->right = buildTree(arr, index, size);

    return root;
}

// Function to print preorder traversal of the tree
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(Node* root)
{
    if(root==NULL)
    {
            return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}
void postorderTraversal(Node* root)

{
    if(root==NULL){
        return;
    }

postorderTraversal(root->left);
postorderTraversal(root->right);
printf("%d ",root->data);

}
