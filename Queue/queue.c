#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int front = -1;
int rear = -1;
int queue[MAX];


//-----FUNCTIONS-----
void insert()
{
    int item;
    printf("Enter the element: ");
    scanf("%d", &item);
    if(rear == MAX-1)
    {
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front++;
        rear++;
    }
    else
        rear++;
    queue[rear] = item;
    printf("%d inserted.\n", item);
}

void delete()
{
    int item;
    if(front == -1 && rear == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }
    else
    {
        item = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front++;
        printf("You deleted %d.\n", item);
    }
}

void display()
{
    int i;
    if(rear == -1)
        printf("Empty queue\n");
    else
    {
        for(int i=front; i<=rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

//-----DRIVER CODE-----
int main()
{
    int choice;
    
    do
    {
        printf("------------------------------\n");
        printf("1. Insert\n2. Delete\n3. Display\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
        }
    }
    while(choice < 4);
    return 0;

}