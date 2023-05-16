#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define SIZE 100

int stack[SIZE], top = -1;

//PUSH
void push(char x)
{
    stack[++top] = x;
}

//POP
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

//check precedence here
int precedence(char operator)
{
	switch(operator)
	{
		case '+':
		case '-': 
			return 1;
		case '*':
		case '/':
			return 2;
		case '^': 
			return 3;
		default: 
            return -1;
	}
}

int isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

//Reversal of string
void reverse(char *infix)
{
    char *rev = malloc(sizeof(char) * strlen(infix));
    int j = 0;

    for (int i = strlen(infix) - 1; i >= 0; --i) 
    {
        rev[j++] = infix[i];
    }
    rev[j] = '\0';
    strcpy(infix,rev);
    free(rev);
}

void infix_to_prefix(char *infix, char *prefix,  int n)
{
    int temp, x;
    int i = 0, j = 0;
    reverse(infix);
    while (infix[i] != '\0')
    {
        temp = infix[i];
        if (isalnum(temp))
        {
            prefix[j++] = temp;
        }
        else if (temp == ')')
            push(temp);
        else if (temp == '(')
        {
            while ((x = pop()) != ')')
            {
                prefix[j++] = x;
            }
        }
        else
        {
            while(precedence(stack[top]) >= precedence(temp))
            {
                prefix[j++] = pop();
            }
            push(temp);
        }
        i++;
    }
    while(top != -1)
        prefix[j++] = pop();
    prefix[j] = '\0';
    reverse(prefix);
}


int evaluate_prefix(char prefix[SIZE], int n)
{
    int n1, n2, n3;
    for(int i = n-1; i>=0; i--)
    {
        if(isdigit(prefix[i]))
        {
            push(prefix[i] - 48);
        }
        else
        {
            n1 = stack[top];
            pop();
            n2 = stack[top];
            pop();
            switch(prefix[i])
            {
                case '+':   {
                    n3 = n1 + n2;
                    break;
                }
                case '-':   {
                    n3 = n1 - n2;
                    break;
                }
                case '*':   {
                    n3 = n1 * n2;
                    break;
                }
                case '/':   {
                    n3 = n1 / n2;
                    break;
                }
                case '^':   {
                    n3 = pow(n1,n2);
                    break;
                }
                default: 
                    break;
            }
            push(n3);
        }
    }
    return pop();
    
}


int main()
{
	char infix[SIZE], prefix[SIZE];     
	int n;

	scanf("%d", &n);
	scanf("%s", infix);

	infix_to_prefix(infix, prefix, n);
    int res = evaluate_prefix(prefix, n);
    printf("%s %d\n", prefix,res);
	return 0;
}