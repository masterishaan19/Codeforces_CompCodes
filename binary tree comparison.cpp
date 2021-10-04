#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *left, *right;
    node *parent;           
}node;
node *create()
{
    node *root = NULL;
	node *temp = NULL;
	printf("Keep Entering Data till -1 is input.....\n");
	int val;
	while(1)
	{
		scanf("%d",&val);
		if(val == -1)
			break;
		else
		{
			temp = root;
			while(1)
			{
				if(temp != NULL)
				{
					if(val < temp->data)
					{
						if(temp->left == NULL)
						{
							node *newn;
							newn = (node *)malloc(sizeof(node));
							newn->data = val;
							newn->left = NULL;
							newn->right = NULL;
							temp->left = newn;
							newn->parent = temp;
							break;
						}
						else
							temp = temp->left;
					}
					else if(val > temp->data)
					{
						if(temp->right == NULL)
						{
							node *newn;
							newn = (node *)malloc(sizeof(node));
							newn->data = val;
							newn->left = NULL;
							newn->right = NULL;
							temp->right = newn;
							newn->parent = temp;
							break;
						}	
						else
							temp = temp->right;
					}
					else
					{
						printf("\t\tUnique Number Please...... \n");
						break;
					}
				}
				else
				{
					root = (node *)malloc(sizeof(node));	
					root->data = val;
					root->left = NULL;
					root->right = NULL;
					root->parent = NULL;
					break;
				}
			}
		}
	}
    return root;
}
void display(node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%d\n",root->data);
        display(root->right);
    }
}
int compare(node *root, node *toor)
{
    if(root != NULL && toor != NULL)
    {
        if(root->data == toor->data)
        {
            int x;
            x = compare(root->left, toor->left);
            if(x == 1)
            {
                x = compare(root->right, toor->right);
                if(x == 1)
                    return 1;
                else    
                    return 0;
            }
            return 0;
        }
        return 0;
    }
    else
    {
        if (root != NULL || toor != NULL)
        {
            return 0;
        }
        return 1;        
    }
    
}
int main()
{
    node *root, *toor;
    root = create();
    toor = create();
    printf("First binary tree is : \n");
    display(root);
    printf("Second bianry tree is : \n");
    display(toor);
    int result;
    result = compare(root, toor);
    if(result == 1)
        printf("Yes, binary trees are equal...\n");
    else    
        printf("No ,binary trees are not equal....\n");
}