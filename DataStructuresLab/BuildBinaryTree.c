#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Program to build binary tree from heap-like input

typedef struct Node{
	struct Node * left;
	struct Node * right;
	int data;
}Node;

Node * createNode(int data){
	Node * temp = (Node * ) malloc(sizeof(Node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	return temp;
}

void treeMaker(Node ** root,int lchild,int * a,int size){
	Node * ref = *root;
	if(lchild < size){
		ref->left = createNode(a[lchild]);
		treeMaker(&(ref->left),2*lchild++,a,size);
	}
	if(lchild < size){
		ref->right = createNode(a[lchild]);
		treeMaker(&(ref->right),2*lchild,a,size);
	}
	return;
}

// Implements inorder traversal of binary tree.
void prinTree(Node * root){
	if(!root) return;
	prinTree(root->left);
	printf("%d ",root->data);
	prinTree(root->right);
}

void deleter(Node * root){
	if(!root) return;
	deleter(root->left);
	deleter(root->right);
	free(root);	
}

int main(){
    int n;
	Node * root = NULL;
	scanf("%d",&n);
	int * a = (int *) malloc(sizeof(int)*(n+1));
	for(int i=1;i<n;++i){
		scanf("%d",a+i);
	}
	if(n > 0){
		root = createNode(a[1]);
		treeMaker(&root,2,a,n);
		prinTree(root);
		
		deleter(root);
		free(a);
	}
    return 0;
}