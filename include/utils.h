#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>

#include "graph.h"

/**
 * @brief Prints the graph.
 *
 * Prints the entire graph structure in a digraph format.
 *
 * @param graph Pointer to the Graph structure.
 */
void print_graph(const struct Graph *graph);

/**
 * @brief Determines if a vertex is a neighbor.
 *
 * Determines if the vertex specified is a neighbor of the src vertex in the graph.
 *
 * @param graph pointer to the Graph structure.
 * @param src the source vertex.
 * @param find the vertex to check.
 * @return true if find is a neighbor of src. false if not.
 */
bool is_neighbor(const struct Graph *graph, int src, int find);


/**
 * @brief Checks if two vertices belong to the same connected component.
 *
 * Checks if the two specified vertices belong to the same connected component in the graph.
 *
 * @param graph pointer to the Graph structure.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @return true if both vertices belong to the same connected component. false if not.
 */
bool same_component(const struct Graph *graph, int src, int dest);

/**
 * @brief Checks if the graph is connected.
 *
 * Checks if the graph is connected.
 *
 * @param graph pointer to the graph structure.
 * @return true if the graph is connected. false if not.
 */
bool is_connected(const struct Graph *graph);

/**
 * @brief Compute the in-degree of a vertex.
 *
 * Compute the number of incoming edges for the specified vertex in the graph.
 *
 * @param graph pointer to the graph structure.
 * @param vertex the vertex for which the in-degree is calculaated.
 * @return the in-degree of the vertex.
 */
size_t in_degree(const struct Graph *graph, int vertex);

/**
 * @brief Compute the out-degree of a vertex.
 *
 * Compute the number of outgoing edges for the vertex (vertex) in the graph.
 *
 * @param graph pointer to the grqph structure.
 * @param vertex the vertex for which we are calculating the out-degree.
 * @return the out-degree of the vertex.
 */
size_t out_degree(const struct Graph *graph, int vertex);

/**
 * @brief Finds the smallest path between two vertices.
 *
 * Finds the smallest path from the start vertex to the stop vertex in the graph.
 *
 * @param graph pointer to the Graph structure.
 * @param start the starting vertex.
 * @param stop the destination vertex.
 * @return a pointer of an array of int representing the smallest path.
 */
int *smallest_path(const struct Graph *graph, int start, int stop);

/**
 * @brief Performs a topological sort on a directed graph.
 *
 * Performs a topological sort on the given directed graph.
 *
 * @param graph pointer to the graph structure.
 * @return a pointer of an array of int representing the topologically sorted order.
 */
int *topological_sort(const struct Graph *graph);

#endif /* UTILS_H */
