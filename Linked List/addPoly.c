#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
    int coeff;
    int pow;
    struct term *next;
} poly;

/** The prototypes */
void create_poly(poly **);
void display(poly *);
void add(poly **, poly *, poly *);


//DRIVER CODE
int main()
{
    poly *poly1, *poly2, *poly3;
    create_poly(&poly1);
    create_poly(&poly2);
    display(poly1);
    display(poly2);
    add(&poly3, poly1, poly2);
    display(poly3);
    return 0;
}


void create_poly(poly **node)
{
    int flag; // A flag to control the menu
    int coeff, pow;
    poly *tmp_node; // To hold the temporary last address
    tmp_node = (poly *)malloc(sizeof(poly)); // create the first node
    *node = tmp_node; // Store the head address to the reference variable
    do
    {
        // Get the user data
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        scanf("%d", &pow);
        tmp_node->pow = pow;

        // Now increase the termed on user condition
        tmp_node->next = NULL;
        // Ask user for continuation,if 1 continue else exit
        scanf("%d", &flag);
        // Grow the termed list on condition
        if (flag)
        {
            tmp_node->next = (poly *)malloc(sizeof(poly)); // Grow the list  
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}
/**
 * The display function
 * Prints the Polynomial in user readable format 
 * @param poly * node The polynomial termed list
 * @return void
 */
void display(poly *node)
{
    printf("\nThe polynomial expression is:\n");
    while (node != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node != NULL)
            printf(" + ");
    }
    printf("\n");
}
/*
 *
 * The polynomial add function
 * Adds two polynomial to a given variable
 * @param poly ** result Stores the result
 * @param poly * poly1 The first polynomial expression
 * @param poly * poly2 The second polynomial expression
 * @return void
 */
void add(poly **result, poly *poly1, poly *poly2)
{ 
    poly * ans;
    ans = (poly*)malloc(sizeof(poly));
    ans->next = NULL;
    *result = ans;

    while(poly1 && poly2)
    {
        if(poly1->pow > poly2->pow)
        {
            ans->pow = poly1->pow;
            ans->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if(poly1->pow < poly2->pow)
        {
            ans->pow = poly2->pow;
            ans->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            ans->pow = poly1->pow;
            ans->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if(poly1 && poly2)
        {
            ans->next = (poly*)malloc(sizeof(poly));
            ans = ans->next;
            ans->next = NULL;
        }
    }
    
    while (poly1 || poly2) 
    {
        ans->next=(poly*)malloc(sizeof(poly));
        ans=ans->next;
        ans->next=NULL;
        if (poly1) 
        {
            ans->pow = poly1->pow;
            ans->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2) 
        {
            ans->pow = poly2->pow;
            ans->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }

}