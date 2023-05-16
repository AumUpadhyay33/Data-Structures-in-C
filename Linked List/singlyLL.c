#include<stdio.h>
#include<stdlib.h>

//----------STRUCTURES----------
typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct llist
{
    NODE *head;
} LLIST;

void initList(LLIST*);
void insertFront(LLIST*, int);
void insertLast(LLIST*, int);
void insertAtPos(LLIST*, int, int);
void deleteFront(LLIST*);
void deleteLast(LLIST*);
void deleteAtPos(LLIST*, int);
void deleteAlt(LLIST*);
void display(LLIST*);
void destroyList(LLIST*);
void search(LLIST*, int);
void reverse(LLIST*);
NODE *getNode(int);


//----------DRIVER CODE----------
int main()
{
    LLIST lobj;
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
            case 6: printf("Enter the position: ");
                    scanf("%d",&pos);
                    deleteAtPos(&lobj,pos);
                    break;
            case 7: display(&lobj);
                    break;
            case 8: destroyList(&lobj);
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
                    display(&lobj);
                    break;

        }
    }
    while (choice);
    return 0;
}
//----------END OF DRIVER CODE----------

//----------FUNCTIONS----------

void initList(LLIST *sll)
{
    sll->head = NULL;
}

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->next = NULL;
    return temp;
}

void insertFront(LLIST *sll, int ele)
{
    NODE *temp = getNode(ele);
    temp->next = sll->head;
    sll->head = temp;
}

void insertLast(LLIST *sll, int ele)
{
    NODE *temp = getNode(ele);
    if(sll->head == NULL)   {
        sll->head = temp;   //insertFront
    }
    else
    {
        NODE *p = sll->head;
        while (p->next != NULL) {
            p = p->next;
        }   
        p->next = temp; 
    }
}

void insertAtPos(LLIST *sll, int ele, int pos)
{
    NODE *temp = getNode(ele);
    if(pos == 0)
    {
        temp->next = sll->head; //insertFront
        sll->head = temp;
    }
    NODE *p = sll->head, *q = NULL;
    for(int i=0; i<pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = temp;
    temp->next = p;
}

void deleteFront(LLIST *sll)
{
    if(sll->head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    NODE *p = sll->head;
    sll->head = p->next;
    printf("You deleted %d\n",p->data);
    free(p);
    
}

void deleteLast(LLIST *sll)
{
    NODE *p = sll->head, *q = NULL;

    if(sll->head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    if(p->next == NULL)
    {
        sll->head = NULL;
    }
    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    printf("You deleted %d\n",p->data);
    free(p);
}

void deleteAtPos(LLIST *sll, int pos)
{   
    NODE *p = sll->head, *q = NULL;
    if(pos == 0)
    {
        sll->head = p->next;
        printf("You deleted %d\n",p->data);
        free(p);
        return;
    }
    else
    {
        for(int i=0; i<pos; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("You deleted %d\n",p->data);
        free(p);
    }
}

void display(LLIST *sll)
{
    NODE *p = sll->head;
    if(sll->head == NULL)
    {
        printf("List is empty!\n");
    }
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void destroyList(LLIST *sll)
{
    NODE *p = sll->head, *q;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    sll->head = NULL;
}

void search(LLIST *sll, int ele)
{
    NODE *p = sll->head;
    int pos = 1;     
    if(sll->head == NULL)
        printf("List is empty!\n");
    else
    {
        while(p->data != ele && p->next != NULL)
        {
            p = p->next;
            pos++;
        }
        if(ele == p->data)
            printf("Element %d found on position %d.\n",ele,pos);   
        else
            printf("Element %d not found!\n",ele);
    }
}
void reverse(LLIST *sll)
{
    NODE *pre = NULL, *curr = sll->head, *nxt = NULL;
    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nxt;
    }
    sll->head = pre;
}
void deleteAlt(LLIST *sll)
{
    NODE *p = sll->head, *c = sll->head;
    while(c != NULL)
    {
        p = c;
        c = c->next;
        p->next = c->next;
        free(c);
        c = p->next;
    }
}