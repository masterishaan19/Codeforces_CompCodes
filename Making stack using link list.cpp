#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *ptr;
}node;
int pop(node **);
node * create();
node * push(node *, int );
void display(node *);
void function();
int main()
{
    printf("\t\t<<<<<<================ Welcome to stack world coorp... ================>>>>>>\n");
    char res = 'y';
    while(1)
    {
        if(res == 'y' || res == 'Y')
            function();
        else 
            break;
        printf("Want to continue [Y]\[N]\n");
        fflush(stdin);
        scanf("%c",&res);
    }   
    printf("<<<<<<========== Thanks for using Stack <-> link list coorp.... =========>>>>>>\n");
}
void function()
{
    int ans;
    int val;
    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Create\n");
        printf("2. Push Element\n");
        printf("3. Pop Elemetn\n");
        printf("4. Display whole stack\n");
        printf("5. Exit\n");
        fflush(stdin);
        scanf("%d",&ans);
        if(ans == 5)
            break;
        node *start;
        switch(ans)
        {
            case 1: start = create(); break;
            case 2: printf("Enter your value:");
                    scanf("%d",&val);
                    start = push(start, val); break;
            case 3: val = pop(&start);
                    printf("So your popped value is : %d", val);
            case 4: display(start);
        }   
    }
}
node * create()
{
    printf("Keep entering data till -1 is not entered:\n");
    node *start;
    int val;
    start = NULL;
    while(1)
    {
        scanf("%d",&val);
        if(val != -1)
        {
            start = push(start, val);
        }
        else
            break;
    }
    return start;
}
node * push(node *start, int val)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->ptr = start;
    return temp;
}
int pop(node **start)
{
    int val = 404;
    if(*start != NULL)
    {
        val = (*start)->data;
        *start = (*start)->ptr;
    }
    return val;
}
void display(node *start)
{
    int val;
    printf("Here comes your data of stack.....\n");
    while(start != NULL)
    {
        val = pop(&start);
        printf("%d\n",val);
    }
}
