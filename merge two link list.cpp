#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *ptr;
}node;
void display(node *root){
	if(root != NULL)
	{
		printf("%d ",root->data);
		display(root->ptr);
	}
}
node *create()
{
	printf("Keep Entering Till -1 is entered : \n");
	node *root, *temp ,*curr;
	root = NULL;
	curr = root;
	temp = NULL;
	int val;
	while(1)
	{
		scanf("%d",&val);
		if(val == -1)
			break;
		else
		{
			curr = (node *)malloc(sizeof(node));
			curr->data = val;
			curr->ptr = NULL;
			if(root == NULL)
			{
				root = curr;
				temp = root;
			}
			else{
				temp->ptr = curr;
				temp = curr;
			}
		}
	}
	return root;
}
node *merge(node *root, node *toor)
{
	node *mergo;
	mergo = root;
	node *temp, *temp2;
	temp = root;
	temp2 = toor;
	node *prev;
	node *next;
	while(temp2 != NULL && temp != NULL)
	{
		if(temp->data <= temp2->data)
		{
			prev = temp;
			temp = temp->ptr;
		}
		else
		{
			prev->ptr = temp2;
			next = temp2->ptr;
			temp2->ptr = temp;
			temp2 = temp2->ptr;
			temp2 = next;
		}
	}
	if(temp == NULL)
		prev->ptr = temp2;
	return mergo;
}
int main()
{
	node *root, *toor;
	root = create();
	toor = create();
	printf("\nFirst list be : \n");
	display(root);
	printf("\nSecond oredered list be : \n");
	display(toor);
	node *mergo;
	if(root->data < toor->data)
		mergo = merge(root, toor);
	else 
		mergo = merge(toor, root);
	printf("\nAfter merging your link list look alike: \n");
	display(mergo);
}
