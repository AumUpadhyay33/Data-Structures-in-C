#include<stdio.h>
#define MAX 10

void dfs(int n, int a[MAX][MAX], int src, int visited[MAX])
{
    int i;
    visited[src] = 1;
    printf("%d",src);
    for(i = 0; i<n; i++)
    {
        if(a[src][i]==1 && visited[i]==0)
        {
            printf("-->");
            dfs(n, a, i, visited);
        }
    }
}

int main()
{
    int n, src;
    int a[MAX][MAX], visited[MAX];
    int count=0;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the source: ");
    scanf("%d", &src);
    for(int i=0; i<n; i++)
    {
        visited[i] = 0;
    }
    dfs(n, a, src, visited);
    for(int i = 0; i<n; i++)
    {
        if(visited[i])
        {
            count++;
        }
    }
    if(count == n)
    {
        printf("\nConnected Graph.");
    }
    else
    printf("\nDisconnected Graph.");
    return 0;
}