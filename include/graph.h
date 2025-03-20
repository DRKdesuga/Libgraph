#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Represents a node in a linked list.
 *
 * This structure contains an int representing a vertex and
 * a pointer to the next node.
 */
struct node
{
    int vertex;
    struct node *next;
};

/**
 * @brief Represents a graph.
 *
 * This structure represents a graph contiaining a flag to see if the grpah is directed or not,
 * the order of the graph, and an adjacency list.
 */
struct Graph
{
    bool directed;
    int order;
    struct node **adj_list;
};

/**
 * @brief Adds an edge to the graph.
 *
 * adds an edge from the source vertex to the destination vertex in the graph.
 *
 * @param graph pointer to the Graph structure.
 * @param src the source vertex.
 * @param dest the destination vertex.
 * @return true if the edge was added successfully false if not.
 */
bool add_edge(struct Graph *graph, int src, int dest);

/**
 * @brief Init a graph.
 *
 * Init a graph with the given number of vertices and directed flag.
 *
 * @param vertices The number of vertices in the graph.
 * @param directed a boolean value indicating if the graph is directed or not.
 * @return Returns a pointer to the newly created Graph structure.
 */
struct Graph *graph_init(int vertices, bool directed);

/**
 * @brief Frees the graph.
 *
 * Free all resources allocated for the grap and destroys the graph structure.
 *
 * @param graph Pointer to the graph structure.
 */
void free_graph(struct Graph *graph);

#endif /* GRAPH_H */
