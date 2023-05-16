#include<stdio.h>
#define MAX 10

typedef struct Stack
{
    int top;
    int S[MAX];
}STACK;

void initStack(STACK *ps)
{
    ps->top = -1;
}

//IF STACK IS FULL!
int isFull(STACK *ps)
{
    return ps->top == MAX-1;
    //If true it will return 1, else 0.
}

//IF STACK IS EMPTY!
int isEmpty(STACK *ps)
{
    return ps->top == -1;
    //If true it will return 1, else 0.
}

//PUSH
int push(STACK *ps, int ele)
{
    if(isFull(ps))
        return 0;
    else
    {
        ps->S[++ps->top] = ele; 
        return 1;
    }
}

//POP
int pop(STACK *ps, int *pe)
{
    if(isEmpty(ps))
        return 0;
    else
    {
        *pe = ps->S[ps->top];
        ps->top--;
        return 1;
    }
}

//PEEK
int peek(STACK *ps, int *pe)
{
    if(isEmpty(ps))
        return 0;
    else
    {
        *pe = ps->S[ps->top];
        return 1;
    }
}
//DISPLAY
void display(STACK *ps)
{
    if(isEmpty(ps))
    {
        printf("Stack empty\n");
        return;
    }
    else
    {
        for(int i=ps->top; i>=0; i--)
        {
            printf("%d\n",ps->S[i]);
        }
    }
}
//-----DRIVER CODE-----
int main()
{
    STACK s;
    initStack(&s);
    int ele,choice;
    do
    {
        printf("-------------------------\n");
        printf("1. Push\n2. Pop\n3. Peep\n4. isEmpty\n5. isFull\n6. Display\n");
        printf("-------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter an integer: ");
                    scanf("%d",&ele);
                    if(push(&s,ele))
                        printf("Pushed %d.\n",ele);
                    else
                        printf("Stack overflow!\n");
                    break;
            case 2: if(pop(&s,&ele))
                        printf("Popped %d.\n",ele);
                    else
                        printf("Stack underflow!\n");
                    break;
            case 3: if(peek(&s,&ele))
                        printf("The top element is %d\n",ele);
                    else
                        printf("Stack is empty!\n");
                    break;
            case 4: if(isEmpty(&s))
                        printf("Stack is empty!\n");
                    else
                        printf("Stack contains elements\n");
                    break;
            case 5: if(isFull(&s))
                        printf("Stack is full!\n");
                    else
                        printf("Can push elements\n");
                    break;
            case 6: display(&s);
                    break;
        }
    }
    while (choice < 7);
    return 0;
}