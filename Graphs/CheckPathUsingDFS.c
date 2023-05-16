#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX], int n)
{
    int src, dest;
    printf("Enter -1 -1 to stop adding edges.\n");
    while(1)
    {
        scanf("%d%d", &src, &dest);
        if(src<0 || dest<0 || src>=n || dest>=n)
            break;
        adj[src][dest] = 1;
    }
}
int dfs(int adj[MAX][MAX], int n, int visited[MAX], int src, int dest)
{
    visited[src] = 1;
    //printf("%d",src);
    for(int i = 0; i<n; i++)
    {
        if(adj[src][i]==1 && visited[i]==0)
        {
            if(i==dest || dfs(adj, n, visited, i, dest))
                return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int src, dest, res;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    createGraph(adj, n);

    printf("Enter the source and destination vertex:\n");
    scanf("%d%d", &src, &dest);

    res = dfs(adj, n, visited, src, dest);
    if(res)
        printf("There exists a path from %d to %d.\n", src, dest);
    else
        printf("There exists no path from %d to %d.\n", src, dest);
    return 0;
}