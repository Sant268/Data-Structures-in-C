#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
void postorder(struct Node* node)
{
	if (node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->data);
}
void inorder(struct Node* node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}
void preorder(struct Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preorder(node->left);
	preorder(node->right);
}
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->right = newNode(7);
    root->right->left = newNode(12);
    root->left->left = newNode(27);
    root->left->right= newNode(54);
    printf("\n Preorder Traversal:");
    preorder(root);
    printf("\n Inorder Traversal:");
    inorder(root);
    printf("\n Postorder Traversal:");
    postorder(root);
    return 0;
}
