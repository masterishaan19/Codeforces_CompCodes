#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
    int data;
    node *left, *right;
}node;
node *create_bt(int , int );
void function(node *);
// ----------------------------------------------------------------
int main()
{
    printf("<< Welcome to Binary tree and its function >> \n");
    node *root;
    root = create_bt(INT_MIN, 0);
    function(root);
}
// ----------------------------------------------------------------
void display(node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }
}
// ----------------------------------------------------------------
void pre(node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        pre(root->left);
        pre(root->right);
    }
}
// ----------------------------------------------------------------
void post(node *root)
{
    if(root != NULL)
    {
        post(root->left);
        post(root->right);
        printf("%d ",root->data);
    }
}
// ----------------------------------------------------------------
void display_bt(node *root)
{
    int ans;
    printf("Enter your choice for type of display :\n");
    printf("1. Pre-order\n");
    printf("2. In-order\n");
    printf("3. Post-order\n");
    scanf("%d",&ans);
    switch(ans)
    {
        case 1: pre(root);break;
        case 3: post(root);break;
        default: display(root);break;
    }
}
// ----------------------------------------------------------------
int max(node *root)
{
    if(root != NULL)
    {
        int x, y, z;
        x = max(root->left);
        y = root->data;
        z = max(root->right);
        if(x > y)
        {
            if(x > z)
                return x;
            else
                return z;
        }
        else
        {
            if(y > z)
                return y;
            else    
                return z;
        }
    }
    else 
        return INT_MIN;
}
// ----------------------------------------------------------------
int min(node *root)
{
    if(root != NULL)
    {
        int x, y, z;
        x = min(root->left);
        y = root->data;
        z = min(root->right);
        if(x < y)
        {
            if(x < z)
                return x;
            else if (z < x)
                return z;
        }
        else if(y < x)
        {
            if(y < z)
                return y;
            else    
                return z;
        }
    }
    else 
        return INT_MAX;
}
// ----------------------------------------------------------------
int sum(node *root)
{
    int x = 0, y = 0, z = 0 ;
    if(root != NULL)
    {
        x = sum(root->left);
        y = root->data;
        z = sum(root->right); 
        return x+y+z;
    }
    return 0;
}
// ----------------------------------------------------------------
int heigth(node *root)
{
    if(root == NULL)
        return 0;
    else
    {
        int lh , rh;
        lh = heigth(root->left);
        rh = heigth(root->right);
        if(lh > rh)
            return lh+1;
        else    
            return rh+1;
    }
}
// ----------------------------------------------------------------
int total_node(node *root)
{
    if(root == NULL)
        return 0;
    else
    {
        int x, y;
        x = total_node(root->left);
        y = total_node(root->right);
        return x+y+1;
    }
}
// ----------------------------------------------------------------
int leaf_node(node *root)
{
    if(root != NULL)
    {
        if(root->left == NULL && root->right == NULL)
            return 1;
        else
        {
            int right, left;
            left = leaf_node(root->left);
            right = leaf_node(root->right);
            return (left + right );
        }
    }
    return 0;
    
}
// ----------------------------------------------------------------
void Search(node *root, int search)
{
   if(root != NULL)
   {
        if(root->data == search)
        {
            display(root);
            printf("\n");            
        }
        else
        {
            Search(root->left, search);
            Search(root->right, search);
        }
        
   }
}
// ----------------------------------------------------------------
void function(node *root)
{
    int result, search;
    while(1)
    {
        int res;
        printf("Enter your choice: \n");
        printf("1. Display\n");
        printf("2. Maximum in binary tree\n");
        printf("3. Minimum in binary tree\n");
        printf("4. Sum of data in binary tree\n");
        printf("5. Height of binary tree\n");
        printf("6. Leaf node of binary tree\n");
        printf("7. Total nodes\n");
        printf("8. Search element in binary tree\n");
        printf("9. Exit\n");
        scanf("%d",&res);
        if(res == 9)
            break;
        else
        {
            switch(res)
            {
                case 1:display_bt(root);break;
                case 2:result = max(root);
                       printf("MAX : %d", result);
                       break;
                case 3:result = min(root);
                        printf("MIN : %d", result);
                        break;
                case 4:result = sum(root);
                        printf("SUM : %d", result);
                        break;
                case 5:result = heigth(root);
                        printf("Height of tree : %d" ,result);
                        break;
                case 6:result = leaf_node(root);
                        printf("Leaf node : %d ",result);
                        break;
                case 7: result = total_node(root);
                        printf("Total number of nodes : %d ", result);
                        break;
                case 8: printf("Enter element to be searched :");
                        scanf("%d",&search);
                        Search(root, search);
                        // if(result = -1)
                        //     printf("............. NO , such element is found.............");
                        break;
                default: printf("Wrong input....\n");break;
            }
        }
        printf("\n");
    }
}
// ----------------------------------------------------------------
node *create_bt(int val, int num)
{
    int value;
	node *root;
	root = (node *)malloc(sizeof(node));
	if(val == INT_MIN)
		printf("Enter root element : ");
	else if(val == 1)
		printf("Enter left child of %d : ", num);
	else
		printf("Enter right child of %d : ", num);
	scanf("%d",&value);
	if(value == -1)
		return NULL;
	else
	{
		root->data = value;
		root->left = create_bt(1, value);
		root->right = create_bt(0, value);
    }
    return root;
}
// ----------------------------------------------------------------