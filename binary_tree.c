#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void preorder(struct node *root) {
	printf("%d ", (root->data));
	if(root->left != NULL)
	preorder(root->left);
	if(root->right != NULL)
	preorder(root->right);
}

struct node* createNode(int data) {
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int main() {
	struct node *root = createNode(1);
	struct node *e2 = createNode(2);
	struct node *e3 = createNode(3);
	struct node *e4 = createNode(4);
	struct node *e5 = createNode(5);
	struct node *e6 = createNode(6);
	struct node *e7 = createNode(7);
	struct node *e8 = createNode(8);
	struct node *e9 = createNode(9);
	struct node *e10 = createNode(10);
	root->left = e2;
	root->right = e3;

	e2->left = e4;
	e2->right = e5;
	e5->left = e8;

	e3->left = e6;
	e3->right = e7;
	e7->left = e9;
	e7->right = e10;
	
	preorder(root);
	printf("\n");
	return 0;
}


