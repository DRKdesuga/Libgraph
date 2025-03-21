#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "traversal.h"
#include "fifo.h"

void print_graph(const struct Graph *graph)
{
    if (!graph)
        return;

    printf("digraph graph {\n");
    for (int i = 0; i < graph->order; i++)
    {
        printf("\t\"%d\" -> {", i);
        struct node *adj = graph->adj_list[i];
        while (adj)
        {
            printf("\"%d\"", adj->vertex);
            if (adj->next)
            {
                printf(" ");
            }
            adj = adj->next;
        }
        printf("};\n");
    }
    printf("}\n");
}

bool is_neighbor(const struct Graph *graph, int src, int find)
{
    if (!graph || src < 0 || src >= graph->order || find < 0
        || find >= graph->order)
    {
        return false;
    }

    struct node *current = graph->adj_list[src];
    while (current)
    {
        if (current->vertex == find)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

static void dfs_component(const struct Graph *graph, int vertex, bool *visited)
{
    visited[vertex] = true;

    struct node *adj = graph->adj_list[vertex];
    while (adj)
    {
        if (!visited[adj->vertex])
            dfs_component(graph, adj->vertex, visited);
        adj = adj->next;
    }
}

bool same_component(const struct Graph *graph, int src, int dest)
{
    if (!graph || src < 0 || src >= graph->order || dest < 0
        || dest >= graph->order)
        return false;

    bool *visited = calloc(graph->order, sizeof(bool));
    if (!visited)
        return false;

    dfs_component(graph, src, visited);
    bool result = visited[dest];

    free(visited);
    return result;
}

bool is_connected(const struct Graph *graph)
{
    if (!graph)
        return false;

    bool *visited = calloc(graph->order, sizeof(bool));
    if (!visited)
        return false;

    dfs_component(graph, 0, visited);
    for (int i = 0; i < graph->order; i++)
    {
        if (!visited[i])
        {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}

size_t in_degree(const struct Graph *graph, int vertex)
{
    if (!graph || vertex < 0 || vertex >= graph->order)
        return 0;

    size_t count = 0;
    for (int i = 0; i < graph->order; i++)
    {
        struct node *adj = graph->adj_list[i];
        while (adj)
        {
            if (adj->vertex == vertex)
            {
                count++;
                break;
            }
            adj = adj->next;
        }
    }
    return count;
}

size_t out_degree(const struct Graph *graph, int vertex)
{
    if (!graph || vertex < 0 || vertex >= graph->order)
        return 0;

    struct node *adj = graph->adj_list[vertex];
    size_t count = 0;
    while (adj)
    {
        count++;
        adj = adj->next;
    }
    return count;
}

static bool bfs__path(const struct Graph *g, int verticle, int *pred, int stop)
{
    struct fifo *q = fifo_init();
    fifo_push(q, verticle);
    pred[verticle] = -1;

    while (!fifo_is_empty(q))
    {
        int cur = fifo_head(q);
        fifo_pop(q);

        if (cur == stop)
        {
            fifo_destroy(q);
            return true;
        }

        struct node *adj = g->adj_list[cur];
        while (adj)
        {
            if (pred[adj->vertex] == -2)
            {
                pred[adj->vertex] = cur;
                fifo_push(q, adj->vertex);
            }
            adj = adj->next;
        }
    }

    fifo_destroy(q);
    return false;
}

static void reverse(int *list, size_t length)
{
    if (!list || length == 0)
        return;

    for (size_t i = 0; i < length / 2; i++)
    {
        int temp = list[i];
        list[i] = list[length - 1 - i];
        list[length - 1 - i] = temp;
    }
}

int *smallest_path(const struct Graph *graph, int start, int stop)
{
    if (!graph || start < 0 || stop < 0 || start >= graph->order
        || stop >= graph->order)
        return NULL;

    int *pred = malloc(graph->order * sizeof(int));
    if (!pred)
    {
        perror("Memory allocation error");
        return NULL;
    }
    for (int i = 0; i < graph->order; i++)
    {
        pred[i] = -2;
    }
    if (!bfs__path(graph, start, pred, stop))
    {
        free(pred);
        return NULL;
    }

    int *path =
        malloc((graph->order + 1) * sizeof(int));
    if (!path)
    {
        perror("Memory allocation error");
        free(pred);
        return NULL;
    }

    int i = 0;
    int current = stop;
    while (current != start)
    {
        path[i++] = current;
        current = pred[current];
    }
    path[i++] = start;

    reverse(path, i);

    path[i++] = -3;

    int *resized_path = realloc(path, sizeof(int) * i);
    if (!resized_path)
    {
        perror("Memory allocation error");
        free(path);
        free(pred);
        return NULL;
    }

    free(pred);
    return resized_path;
}

static void topological_sort_util(const struct Graph *graph, int vertex, bool *visited, int *stack, int *stack_index) {
    visited[vertex] = true;

    struct node *adj = graph->adj_list[vertex];
    while (adj) {
        if (!visited[adj->vertex]) {
            topological_sort_util(graph, adj->vertex, visited, stack, stack_index);
        }
        adj = adj->next;
    }

    stack[(*stack_index)++] = vertex;
}

int *topological_sort(const struct Graph *graph) {
    if (!graph || graph->directed == false) {
        fprintf(stderr, "Error: Topological sort requires a directed graph.\n");
        return NULL;
    }

    bool *visited = calloc(graph->order, sizeof(bool));
    if (!visited) {
        perror("Error allocating memory for visited array");
        return NULL;
    }

    int *stack = malloc(graph->order * sizeof(int));
    if (!stack) {
        perror("Error allocating memory for topological stack");
        free(visited);
        return NULL;
    }

    int stack_index = 0;

    for (int i = 0; i < graph->order; i++) {
        if (!visited[i]) {
            topological_sort_util(graph, i, visited, stack, &stack_index);
        }
    }

    for (int i = 0; i < stack_index / 2; i++) {
        int temp = stack[i];
        stack[i] = stack[stack_index - 1 - i];
        stack[stack_index - 1 - i] = temp;
    }

    free(visited);
    return stack;
}
