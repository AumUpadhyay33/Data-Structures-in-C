#include<stdio.h>
#include<stdlib.h>

//----------STRUCTURES----------
typedef struct node
{
    int data;
    struct node *prev, *next;
}NODE;

typedef struct cdllist
{
    NODE *head;
}CDLL;

//----------FUNCTIONS----------
void initList(CDLL *cdll)
{
    cdll->head = NULL;
}
void display(CDLL *cdll)
{
    NODE *p = cdll->head;
    if(cdll->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    do
    {
        printf("%d\n", p->data);
        p = p->next;
    } while (p != cdll->head);
    
}
void insertFront(CDLL *cdll, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    if(cdll->head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        cdll->head = temp;
        return;
    }
    temp->next = cdll->head;
    temp->prev = cdll->head->prev;
    cdll->head->prev->next = temp;
    cdll->head->prev = temp;
    cdll->head = temp;  
}
void insertLast(CDLL *cdll, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    if(cdll->head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        cdll->head = temp;
        return;
    }
    temp->next = cdll->head;
    temp->prev = cdll->head->prev;
    cdll->head->prev->next = temp;
    cdll->head->prev = temp;
}

void insertAtPos(CDLL *cdll, int ele, int pos)  //Write code to count nodes!!1
{
    if(pos == 0)
    {
        insertFront(cdll,ele);
        return;
    }
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    if(cdll->head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        cdll->head = temp;
        return;
    }
    NODE *p = cdll->head, *q = NULL;

    for(int i=0; i<pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = temp;
        temp->prev = q;
        temp->next = p;
        p->prev = temp;
}
void deleteFront(CDLL *cdll)
{
    if(cdll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE *p = cdll->head;
    if(p == p->next)
    {
        printf("You deleted %d.\n", p->data);
        cdll->head = NULL;
        free(p);
        return;
    }
    cdll->head = cdll->head->next;
    cdll->head->prev = p->prev;
    p->prev->next = cdll->head;
    printf("You deleted %d.\n", p->data);
    free(p);
}
void deleteLast(CDLL *cdll)
{
    if(cdll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE *p = cdll->head;
    if(p == p->next)
    {
        printf("You deleted %d.\n", p->data);
        cdll->head = NULL;
        free(p);
        return;
    }
    p = cdll->head->prev;
    cdll->head->prev = p->prev;
    p->prev->next = cdll->head;
    printf("You deleted %d.\n", p->data);
    free(p);
}

//----------DRIVER CODE----------
int main()
{
    CDLL lobj;
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
            case 5: deleteLast(&lobj);
                    break;
            /*case 6: printf("Enter the position: ");
                    scanf("%d",&pos);
                    deleteAtPos(&lobj,pos);
                    break;*/
            case 7: display(&lobj);
                    break;
            /*case 8: destroyList(&lobj);
                    break;
            case 9: printf("Enter the element you want to search: ");
                    scanf("%d", &ele);
                    search(&lobj,ele);
                    break;
            case 10: printf("The linked list before reversal:\n");
                    display(&lobj);
                    printf("The linked list after reversal:\n");
                    reverse(&lobj);
                    display(&lobj);
                    break;
            case 11: deleteAlt(&lobj);
                    break;*/

        }
    }
    while (choice);
    return 0;
}