#include<stdio.h>
#include<stdlib.h>

//STRUCTURES
typedef struct dequeue
{
    struct node *front, *rear;
} DQ;
typedef struct node
{
    int data;
    struct node *prev, *next;
} NODE;

struct DQ dq;

//FUNCTIONS
void init(DQ *dq)
{
    dq->front = NULL;
    dq->rear = NULL;
}

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->prev = NULL;
    temp->next=NULL;
    return temp;
}

void insertFront(DQ *dq,int ele)
{
    NODE *temp = getNode(ele);

    if(dq->front == NULL)
        dq->front = dq->rear = temp;
    else
    {
        temp->next = dq->front = temp;
        dq->front->prev = temp;
        temp->prev = NULL;
        dq->front = temp;
    }
}

void insertLast(DQ *dq, int ele)
{
    NODE *temp = getNode(ele);

    if(dq->front == NULL)
        dq->front = dq->rear = NULL;
}

