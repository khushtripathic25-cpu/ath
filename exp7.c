#include <stdio.h>

int graph[20][20];
int visited[20];
int n;

void DFS(int vertex)
{
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 &&
            visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of buildings: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Enter between 1 and 20 buildings.\n");
        return 0;
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting building (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting building!\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}