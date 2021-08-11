#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

/*
* Struct Binary Tree
*/
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

/* Função que gera um novo nó para arvore. */
Node* newNode(int data)
{
	Node* node
		= (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* Pós-Ordem */
void printPostorder(struct node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	printf("%d ", node->data);
}

/* In-Ordem*/
void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	printf("%d ", node->data);

	/* now recur on right child */
	printInorder(node->right);
}

/* Pré-Ordem*/
void printPreorder(struct node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	printf("%d ", node->data);

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

/*Imprime formatado*/
void print2DTree(struct node *root, int space)
{
	// Caso base;
	if (root == NULL)
		return;

	// Aumento da distância entre os níveis
	space += COUNT;

	// Avalia primeiro o nó direita
  // Vai empilhar todas subárvores direitas;
	print2DTree(root->right, space);

	// Imprime o nó no retorno da recursão
		for (int i = COUNT; i < space; i++)
		  printf(" ");
	printf("%d\n", root->data);

	// Avalia o nó esquerda
	print2DTree(root->left, space);
}


/* Driver program to test above functions*/
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
  root->right->left = newNode(10);
  root->right->right = newNode(15);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("\nÁrvore Binária: \n");
  print2DTree(root, 0);

	printf("\nTravessia Pré-Ordem: \n");
	printPreorder(root);

	printf("\nTravessia In-Ordem: \n");
	printInorder(root);

	printf("\nTravessia Pós-Ordem: \n");
	printPostorder(root);

	return 0;
}


