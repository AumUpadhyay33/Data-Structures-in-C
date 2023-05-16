#include<stdio.h>
#include<stdlib.h>

//----------STRUCTURES----------
typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct cllist
{
    NODE *last;
}CLL;

//----------FUNCTIONS----------
int countNodes(CLL *cll)
{
    if(cll->last == NULL)
    {
        return 0;
    }
    NODE *p = cll->last->next;
    int count = 0;

    while(p != cll->last)
    {
        p = p->next;
        count++;
    }
    count++;  
    return count;  //for counting the last node in the linked list.
}
void initList(CLL *cll)
{
    cll->last = NULL;
}

void insertFront(CLL *cll, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;

    if(cll->last == NULL)
    {
        cll->last = temp;
        cll->last->next = temp;
        return;
    }
    temp->next = cll->last->next;
    cll->last->next = temp;
}

void insertLast(CLL *cll, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;

    if(cll->last == NULL)
    {
        cll->last = temp;
        cll->last->next = temp;
        return;
    }
    temp->next = cll->last->next;
    cll->last->next = temp;
    cll->last = cll->last->next;
}
void insertAtPos(CLL *cll, int ele, int pos)
{
    int c = countNodes(cll);
    if(pos>c || pos<0)
    {
        printf("Invalid position!\n");
        return;
    }
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    if(pos == 0)
    {
        if(cll->last == NULL)
        {
            cll->last = temp;
            cll->last->next = temp;
            return;
        }
        else
        {
            temp->next = cll->last->next;
            cll->last->next = temp;
            return;
        }
    }
    NODE *p = cll->last->next, *q = NULL;
    for(int i=0; i<pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = temp;
    temp->next = p;
    if(pos == c)
    {
        cll->last = cll->last->next;
    }
    
}

void deleteFront(CLL *cll)
{
    if(cll->last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    NODE *p = cll->last->next;
    
    if(cll->last->next == cll->last)
    {
        cll->last = NULL;
        printf("You deleted %d. \n", p->data);
        free(p);
        return;
    }
    else
    {
        cll->last->next = p->next;
        printf("You deleted %d. \n", p->data);
        free(p);
    }
}
void deleteLast(CLL *cll)
{
    if(cll->last == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    NODE *p = cll->last->next;
    if(cll->last->next == cll->last)
    {
        cll->last = NULL;
        printf("You deleted %d. \n", p->data);
        free(p);
        return;
    } 
    //-----INCOMPLETE-----
}
void deleteAtPos(CLL *cll, int pos)
{
    if(cll->last == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    int c = countNodes(cll);
    if(pos>c || pos<0)
    {
        printf("Invalid position!\n");
        return;
    }
    NODE *p = cll->last->next, *q = NULL;
    if(pos == 0)
    {
        cll->last->next = p->next;
        printf("You deleted %d. \n", p->data);
        if(p->next==p)
		    cll->last=NULL;
        free(p);
        return;
    }
    for(int i=0; i<pos; i++)
    {
        q = p;
        p = p->next;
    }

    q->next = p->next;
    printf("You deleted %d\n",p->data);
    if((pos+1) == c)
        cll->last = q;
    free(p);
}

void display(CLL *cll)
{
    if(cll->last == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    NODE *p = cll->last->next;
    do{
        printf("%d\n", p->data);
        p = p->next;
    }
    while(p != cll->last->next);
}

void destroyList(CLL *cll)
{
    if(cll->last == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    NODE *p = cll->last->next, *q = NULL;
    while(p != cll->last)
    {
        q = p;
        p = p->next;
        free(q);
    }
    free(p);
    cll->last = NULL;
    printf("List destroyed!\n");
}



//----------DRIVER CODE----------
int main()
{
    CLL lobj;
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
            /*case 9: printf("Enter the element you want to search: ");
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