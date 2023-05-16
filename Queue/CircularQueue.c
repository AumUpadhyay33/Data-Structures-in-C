#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    if((rear+1) % MAX == front)
    {
        printf("Queue overflow!\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
    }
    else
        rear++;
    queue[rear] = ele;
    printf("%d inserted.\n", ele);
}
void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue underflow!\n");
        return;
    }
    else if(front == rear)
    {
        printf("%d deleted.\n",queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("%d deleted.\n",queue[front]);
        front = (front+1) % MAX;
    }
}

void display()
{
    int i = front;
    if(front == -1 && rear == -1)
        printf("Empty queue\n");
    else
    {
        for(i=front;i!=rear;(i+1) % MAX)
        {
            printf("%d \n",queue[i]);
            i = (i+1) % MAX;
        }
        printf("%d \n",queue[i]);
    }
}

int main()
{
    int choice;
    do
    {
        printf("-------------------------\n");
        printf("1. Insert\n2. Delete\n3. Display\n");
        printf("-------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
        }
    }
    while(choice < 4);
    return 0;
}