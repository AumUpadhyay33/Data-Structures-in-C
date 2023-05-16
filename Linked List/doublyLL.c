#include<stdio.h>
#include<stdlib.h>

//----------STRUCTURES----------
typedef struct node
{
    int data;
    struct node *prev, *next;
}NODE;

typedef struct dllist
{
    NODE *head;
}DLLIST;
//----------END OF STRUCTURES----------

void initList(DLLIST*);
void insertFront(DLLIST*, int);
void insertLast(DLLIST*, int);
void insertAtPos(DLLIST*, int, int);
void deleteFront(DLLIST*);
void deleteLast(DLLIST*);
void deleteAtPos(DLLIST*, int);
void display(DLLIST*);
NODE *getNode(int);

//----------DRIVER CODE----------
int main()
{
    DLLIST lobj;
    initList(&lobj);
    int choice, ele, pos;

    do
    {
        printf("------------------------------------------------------------\n");
        printf("1. Insert in front\n2. Insert at last\n3. Insert at a position\n4. Delete from front\n5. Delete from Last\n6. Delete from a position\n7. Display\n8. Destroy List\n9. Search an element\n10. Reversal of the linked list\n11. Delete alternate elements\n");
        printf("------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter an integer: ");
                    scanf("%d",&ele);
                    insertFront(&lobj,ele);
                    break;
            case 2: printf("Enter an integer: ");
                    scanf("%d",&ele);
                    insertLast(&lobj,ele);
                    break;
            case 3: printf("Enter an integer: ");
                    scanf("%d",&ele);
                    printf("Enter the position: ");
                    scanf("%d",&pos);
                    insertAtPos(&lobj,ele,pos);
                    break;
            case 4: deleteFront(&lobj);
                    break;
            /*case 5: deleteLast(&lobj);
                    break;
            case 6: printf("Enter the position: ");
                    scanf("%d",&pos);
                    deleteAtPos(&lobj,pos);
                    break;*/
            case 7: display(&lobj);
                    break;
            /*case 8: destroyList(&lobj);
                    break; */

        }
    }
    while (choice);
    return 0;
}
//----------END OF DRIVER CODE----------

//----------FUNCTIONS----------

void initList(DLLIST *dll)
{
    dll->head = NULL;
}

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->prev = NULL;
    temp->next=NULL;
    return temp;
}

void insertFront(DLLIST *dll, int ele)
{
    NODE *temp = getNode(ele);
    temp->next = dll->head;
    if(dll->head == NULL)
    {
        dll->head->prev = temp;
    }
    dll->head = temp;
}

void insertLast(DLLIST *dll, int ele)
{
    NODE *temp = getNode(ele);
    NODE *p = dll->head;
    if(dll->head = NULL)
    {
        dll->head = temp;
        return;
    }
    while(p->next!=NULL)
        p = p->next;
        p->next = temp;
        temp->prev = p;
}
void insertAtPos(DLLIST *dll, int ele, int pos)
{
    NODE *temp = getNode(ele);
    if(pos == 0)
    {
        temp->next = dll->head;
        if(dll->head!=NULL)
            dll->head->prev = temp;
        dll->head = temp;
        return;
    }
    NODE *p = dll->head, *q = NULL;
    for(int i=0; i<pos; i++)
    {
        q->next = temp;
        temp->prev = q;
        temp->next = p;
        p->prev = temp;
    }
}
void deleteFront(DLLIST *dll)
{
    NODE *p = dll->head;
    if(dll->head = NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    dll->head = p->next;
    printf("You deleted %d\n",p->data);
    free(p);
}

void display(DLLIST *dll)
{
    if(dll->head == NULL)
    {
        printf("\nThe List is empty.");
        return;
    }
    NODE *p = dll->head;
    while(p!=NULL)
    {
        printf("%3d",p->data);
        p = p->next;
    }
}