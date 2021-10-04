#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *left, *right;
}node;
void create_bt(node *root, int, int);
void display(node *root);
int main()
{
	printf("\t\t <<< Welcome to binary tree >>> \n");
	node *root;
	create_bt(&root, 0, 0);
	display(root);
}
void create_bt(node **root, int value, int val)
{
	int num;
	if(val == 0)
		printf("Enter your root value :");
	else if(val == 1)
		printf("Enter left child of %d :",value);
	else	
		printf("Enter right child of %d :", value);
	scanf("%d",&num);
	if(num == -1)
	{
		(*root) = NULL;
		return;
	}
	else
	{
		(*root)->data = num;

	}
	

}
void display(node *root)
{
	if(root != NULL)
	{
		display(root->left);
		printf("%d ",root->data);
		display(root->right);
	}
}