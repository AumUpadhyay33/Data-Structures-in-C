#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct trie
{
    int isleaf;
    struct trie *child[26];
    char *value;
}TRIE;

TRIE *createNode()
{
    TRIE *temp = malloc(sizeof(TRIE));
    temp->isleaf = NULL;
    for(int i=0; i<26; i++)
        temp->child[i] = NULL;
    temp->value = NULL;
    return temp;
}

void insert(TRIE *root, char *pattern, char *str)
{
    TRIE *cur = root;
    while(*pattern)
    {
        if(cur->child[*pattern - 'a'] == NULL)
            cur->child[*pattern - 'a'] = createNode();
        cur = cur->child[*pattern - 'a'];
        pattern++;
    }
    cur->isleaf = 1;
    cur->value = malloc(sizeof(str)+1);
    strcpy(cur->value,str);
}

int search(TRIE *root, char *pattern, char *str)
{
    TRIE *cur = root;
    while(*pattern)
    {
        if(cur->child[*pattern - 'a'] == NULL)
            return 0;
        cur = cur->child[*pattern - 'a'];
        pattern++;
    }
    if(cur->value)
    {
        strcpy(str,cur->value);
        return 1;
    }
    return 0;
}

void display(TRIE *root, char *str, int level)
{
    if(root->isleaf)
    {
        str[level] = '\0';
        printf("%s\n", str);
    }
    for(int i=0; i<26; i++)
    {
        if(root->child[i] != NULL)
        {
            str[level] = i + 'a';
            display(root->child[i], str, level+1);
        }
    }
}
int isEmpty(TRIE *root)
{
    for(int i=0; i<26; i++)
    {
        if(root->child[i] != NULL)
            return 0;
    }
    return 1;
}

TRIE *delete(TRIE *root, char *str, int length, int level)
{
    if(root == NULL)
        return root;
    
    if(level == length)
    {
        if(root->isleaf)
            root->isleaf = 0;
        if(isEmpty(root))
        {
            free(root);
            return NULL;
        }
        return root;
    }
    int index = str[level] - 'a';
    root->child[index] = delete(root->child[index], str, length, level+1);
    if(root->isleaf == 0 && isEmpty(root))
    {
        free(root);
        root = NULL;
    }
    return root;
}

void main()
{
    TRIE *root = createNode();
    char str[50];
    insert(root,"act","pretend");
    if(search(root,"act",str))
        printf("Word found and its meaning is: %s",str);
    else
        printf("\nWord not found!\n");
    if(search(root,"ac",str))
        printf("Word found and its meaning is: ",str);
    else
        printf("\nWord not found!\n");
}