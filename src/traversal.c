#include "traversal.h"
#include "graph.h"
#include "fifo.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



static void dfs(const struct Graph *g, int verticle, bool *seen)
{
    struct node *adj = g->adj_list[verticle];
    while (adj != NULL)
    {
        int i = adj->vertex;
        if (!seen[i])
        {
            seen[i] = true;
            printf("%d\n", i);
            dfs(g, i, seen);
        }
        adj = adj->next;
    }
}

void dfs_print(const struct Graph *graph)
{
    bool *seen = calloc(graph->order, sizeof(bool));
    if (!seen)
    {
        perror("Allocation failed");
        return;
    }

    int component = 1;
    for (int i = 0; i < graph->order; i++)
    {
        if (!seen[i])
        {
            printf("Component %d:\n", component);
            seen[i] = true;
            printf("%d\n", i);
            dfs(graph, i, seen);
            component++;
        }
    }

    free(seen);
}

static void bfs(const struct Graph *g, int verticle, int *level)
{
    struct fifo *q = fifo_init();
    fifo_push(q, verticle);
    level[verticle] = 0;
    while (!fifo_is_empty(q))
    {
        int cur = fifo_head(q);
        fifo_pop(q);
        printf("From source: %d, level is: %d at verticle : %d \n", verticle,
               level[cur], cur);

        struct node *adj = g->adj_list[cur];
        while (adj)
        {
            if (level[adj->vertex] == -1)
            {
                level[adj->vertex] = level[cur] + 1;
                fifo_push(q, adj->vertex);
            }
            adj = adj->next;
        }
    }
    fifo_destroy(q);
}

void bfs_print(const struct Graph *graph)
{
    int *level = malloc(graph->order * sizeof(int));
    if (!level)
    {
        perror("Erreur d'allocation mémoire pour 'level'");
        return;
    }
    for (int i = 0; i < graph->order; i++)
    {
        level[i] = -1;
    }
    int component = 1;
    for (int i = 0; i < graph->order; i++)
    {
        if (level[i] == -1)
        {
            printf("Component %d ------->\n", component);
            bfs(graph, i, level);
            component += 1;
        }
    }
    free(level);
}
