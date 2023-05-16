#include<stdio.h>
#include<stdlib.h>

typedef struct trie
{
    int isleaf;
    struct trie *child[26];
}TRIE;

TRIE *createNode()
{
    TRIE *temp = malloc(sizeof(TRIE));
    temp->isleaf = NULL;
    for(int i=0; i<26; i++)
        temp->child[i] = NULL;
    return temp;
}

void insert(TRIE *root, char *pattern)
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
}

int search(TRIE *root, char *pattern)
{
    TRIE *cur = root;
    while(*pattern)
    {
        if(cur->child[*pattern - 'a'] == NULL)
            return 0;
        cur = cur->child[*pattern - 'a'];
        pattern++;
    }
    return cur->isleaf;
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
    char str[20];
    insert(root, "desi");
    insert(root, "designer");
    insert(root, "data");
    insert(root, "any");
    printf("-----Words in trie:-----\n");
    display(root, str, 0);
    delete(root, "desi", 4, 0);
    printf("-----After deleting desi:-----\n");
    display(root, str, 0);
    delete(root, "any", 3, 0);
    printf("-----After deleting any:-----\n");
    display(root, str, 0);
    
    
    /*if(search(root,"desi"))
        printf("desi is present!\n");
    else
        printf("desi is not present!\n");

    if(search(root,"design"))
        printf("design is present!\n");
    else
        printf("design is not present!\n");*/
}