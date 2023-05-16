#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *top = NULL;

void push(int ele)
{
    NODE *tmp = malloc(sizeof(NODE));
    tmp->data = ele;
    if(top == NULL)
    {
        top = tmp;
        tmp->next = NULL;
        return;
    }
    tmp->next = top;
    top = tmp;
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    NODE *p = top;
    top = top->next;
    printf("%d popped\n",p->data);
    free(p);
}
void peek()
{
    if(top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("The top element is %d\n",top->data);
}
void display()
{
    NODE *p = top;
    if(top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    while(p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}
int main()
{
    
    int ele,choice;
    do
    {
        printf("-------------------------\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n");
        printf("-------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter an integer: ");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
        }
    }
    while (choice < 6);
    return 0;
}