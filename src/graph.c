#include "graph.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Graph *graph_init(int verticles, bool directed)
{
    struct Graph *g = malloc(sizeof(struct Graph));
    if (!g)
    {
        perror("Graph memory allocation failed");
        return NULL;
    }
    g->directed = directed;
    g->order = verticles;
    g->adj_list = calloc(verticles, sizeof(struct node));
    if (!g->adj_list)
    {
        perror("Graph adj_list memory allocation failed");
        free(g);
        return NULL;
    }
    return g;
}

bool add_edge(struct Graph *graph, int src, int dest)
{
    if (!graph || src < 0 || dest < 0 || src >= graph->order
        || dest >= graph->order)
        return false;

    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node)
        return false;
    new_node->vertex = dest;
    new_node->next = NULL;
    if (graph->adj_list[src] == NULL || graph->adj_list[src]->vertex > dest)
    {
        new_node->next = graph->adj_list[src];
        graph->adj_list[src] = new_node;
        return true;
    }
    struct node *current = graph->adj_list[src];
    while (current->next != NULL && current->next->vertex < dest)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;

    return true;
}

void free_graph(struct Graph *graph)
{
    if (!graph)
    {
        return;
    }
    for (int i = 0; i < graph->order; i++)
    {
        struct node *current = graph->adj_list[i];
        while (current)
        {
            struct node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adj_list);
    free(graph);
}
