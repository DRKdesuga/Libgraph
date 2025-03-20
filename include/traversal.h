#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "graph.h"

/**
 * @brief Prints the graph using depth-first search.
 *
 * Prints the vertices of the graph using a depth-first search traversal.
 *
 * @param graph Pointer to the graph structure.
 */
void dfs_print(const struct Graph *graph);

/**
 * @brief Prints the graph using breadth-first search.
 *
 * Prints the vertices of the graph using a breadth-first search traversal.
 *
 * @param graph pointer to the Graph structure.
 */
void bfs_print(const struct Graph *graph);

#endif /* TRAVERSAL_H */
