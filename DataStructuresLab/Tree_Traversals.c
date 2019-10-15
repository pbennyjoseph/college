#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = x;
    return temp;
}

Node *insert(Node *root, int x)
{
    if (root == NULL)
        return newNode(x);
    if (root->data > x)
        root->left = insert(root->left, x);
    else if (root->data < x)
        root->right = insert(root->right, x);
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%2d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%2d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%2d ", root->data);
    }
}
int main()
{
    Node *root = NULL;
    int arr[] = {2, 6, 4, 10, 5, 8, 3, 1, 9, 15, 12, 14}, i = 0;
    for (i = 0; i < 12; ++i)
    {
        root = insert(root, arr[i]);
    }

    printf("Inorder Traversal is:\t");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal is:\t");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal is:\t");
    postorder(root);
    printf("\n");

    return 0;
}