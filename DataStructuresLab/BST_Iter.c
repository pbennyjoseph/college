/*
Name: P Benny Joseph
Date: 26 Nov 2019
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node * left;
	struct Node * right;
} Node;

void insert(Node ** root,int data){
	Node * newNode = (Node *) malloc(sizeof(Node));
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;
	if(!*root){
		*root = newNode;
		return;
	}
	Node * ref = *root;
	while(1){
		if(ref->data < data && ref->right){
			ref = ref->right;
		}
		else if(ref->data > data && ref->left){
			ref = ref->left;
		}
		else break;
	}
	if(ref->data == data) return;
	if(ref->data < data) ref->right = newNode;
	else ref->left =  newNode;
}

// This function deletes the given Node (root)
void delete(Node ** root,int data){
	if(!root) return;
	Node * temp,*ref = *root,*par,*del;
	
	// If the node to be deleted has two children
	if(ref->left && ref->right){
		if(ref->right->left){
			
			par = ref->right;
			while(par->left->left)
				par = par->left;
			del = par->left;
			// 'del' is the inorder successor, 'par' is its parent
			
			par->left = del->right;
			del->left = ref->left;
			del->right = ref->right;
			*root = del;
			
		}
		// if current node's right child doesnot have left child,
		// then it is the minimum (inorder successor);
		else{
			ref->right->left = ref->left;
			*root = ref->right;
		}
	}
	// Only has left child;
	else if(ref->left){
		temp = ref->left;
		*root = temp;
		free(ref);
	}
	// Only has right child;
	else if(ref->right){
		temp = ref->right;
		*root = temp;
		free(ref);
	}
	// Is a leaf node;
	else{
		free(ref);
		*root = NULL;
	}
}

// Takes in the root of the tree and data to be deleted
// Finds the node with data in the tree and
// calls the delete function with node to be deleted
void deleteNode(Node * root,int data){
	Node * ref = root;
	while(ref){
		if(data < ref->data){
			if(ref->left && ref->left->data == data){
				delete(&(ref->left),data);
				break;
			}
			ref = ref->left;
		}
		else if(data > ref->data){
			if(ref->right && ref->right->data==data){
				delete(&(ref->right),data);
				break;
			}
			ref = ref->right;
		}
		else{
			delete(&ref,data);
			break;
		}
	}
}

void display(Node * root){
	if(root){
		display(root->left);
		printf("%d ",root->data);
		display(root->right);
	}
}

int main(){
	int n,m,i,temp;
	Node * root = NULL;
	scanf("%d %d",&n,&m);
	for(i = 0;i < n;++i){
		scanf("%d",&temp);
		insert(&root,temp);
		printf("Inserting %4d ::\t",temp);
		display(root);
		printf("\n");
	}
	for(i=0;i < m; ++i){
		scanf("%d",&temp);
		deleteNode(root,temp);
		printf("Deleting %4d ::\t",temp);
		display(root);
		printf("\n");
	}
	return 0;
}