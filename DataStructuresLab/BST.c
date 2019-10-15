#include <stdio.h>
#include <stdlib.h>

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
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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

Node *deleteNode(Node *root, int k)
{
    // Base case
    if (root == NULL)
        return root;

    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }

    // We reach here when root is the node
    // to be deleted.

    // If one of the children is empty
    if (root->left == NULL)
    {
        Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        Node *temp = root->left;
        free(root);
        return temp;
    }

    // If both children exist
    else
    {

        Node *succParent = root->right;

        // Find successor
        Node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        succParent->left = succ->right;

        // Copy Successor Data to root
        root->data = succ->data;

        // Delete Successor and return root
        free(succ);
        return root;
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
    inorder(root);
    printf("\n");
    root = deleteNode(root, 2);
    inorder(root);
    printf("\n");
    root = deleteNode(root, 1);
    inorder(root);
    printf("\n");
    root = deleteNode(root, 15);
    inorder(root);
    printf("\n");
    root = insert(root, 150);
    inorder(root);
    printf("\n");
    return 0;
}