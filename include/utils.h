#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>

#include "graph.h"

// Print the graph's adjacency list
void print_graph(const struct Graph *graph);

// Check if two vertices are neighbors
bool is_neighbor(const struct Graph *graph, int src, int find);

// Check if two vertices belong to the same connected component
bool same_component(const struct Graph *graph, int src, int dest);

// Check if the graph is connected
bool is_connected(const struct Graph *graph);

// Compute the in-degree of a vertex
size_t in_degree(const struct Graph *graph, int vertex);

// Compute the out-degree of a vertex
size_t out_degree(const struct Graph *graph, int vertex);

// Find the shortest path between two vertices
int *smallest_path(const struct Graph *graph, int start, int stop);

// Perform a topological sort on a directed acyclic graph
int *topological_sort(const struct Graph *graph);

#endif /* UTILS_H */
