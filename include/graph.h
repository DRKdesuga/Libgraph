#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct Graph
{
    bool directed;
    int order;
    struct node **adj_list;
};

bool add_edge(struct Graph *graph, int src, int dest);
struct Graph *graph_init(int verticles, bool directed);
void free_graph(struct Graph *graph);

#endif /* GRAPH_H */
