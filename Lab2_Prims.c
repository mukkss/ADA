#include <stdio.h>
#define INFI 99
int edges[10][3], n, wt[10][10];
void prims();
void update(int u[], int v, int i, int *mincost, int lowcost[], int visited[]);
void main()
{
    int i, j;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &wt[i][j]);
        }
    }
    prims();
}
void prims()
{
    int u[10], lowcost[10], visited[10];
    int min, mincost = 0, i, j, v;
    // Mark nodes as unvisited
    visited[1] = 1;
    for (i = 2; i <= n; i++)
    {
        visited[i] = 0;
        u[i] = 1;
        lowcost[i] = wt[1][i];
    }
    for (i = 1; i <= n - 1; i++)
    {
        min = lowcost[2];
        v = 2;
        for (j = 3; j <= n; j++)
        {
            if (lowcost[j] < min)
            {
                min = lowcost[j];
                v = j;
            }
        }
        update(u, v, i, &mincost, lowcost, visited); // Calling the new function
    }
    printf("\n\nThe edges of this minimum cost spanning tree are\n");
    for (i = 1; i <= n - 1; i++)
    {
        printf("(%d,%d)\n", edges[i][1], edges[i][2]);
    }
    printf("\nMinimum cost Spanning Tree is: %d\n", mincost);
}

void update(int u[], int v, int i, int *mincost, int lowcost[], int visited[])
{
    edges[i][1] = u[v];
    edges[i][2] = v;
    *mincost += lowcost[v];
    visited[v] = 1;
    lowcost[v] = INFI;
    for (int j = 2; j <= n; j++)
    {
        if (wt[v][j] < lowcost[j] && !visited[j])
        {
            lowcost[j] = wt[v][j];
            u[j] = v;
        }
    }
}
