# libgraph: A Lightweight Graph Library

**libgraph** is a simple and efficient C library for working with graphs. It provides a clean implementation of directed and undirected graphs using adjacency lists. The library includes utilities for graph traversal, degree calculation, connectivity checks, shortest path finding, and topological sorting.

---

## **Implemented Structures**

### 1. **Graph**
Represents a graph structure using adjacency lists.

```c
struct Graph {
    bool directed;          // Indicates if the graph is directed
    int order;              // Number of vertices in the graph
    struct node **adj_list; // Array of adjacency lists
};
```

### 2. **Node**
Represents a single edge in the adjacency list.

```c
struct node {
    int vertex;          // Destination vertex
    struct node *next;   // Pointer to the next edge
};
```

---

## **Available Functions**

### **Graph Management**
- **`struct Graph *graph_init(int vertices, bool directed);`**
  Initializes a graph with the specified number of vertices and directed/undirected property.

- **`bool add_edge(struct Graph *graph, int src, int dest);`**
  Adds an edge between `src` and `dest` in the graph.

- **`void free_graph(struct Graph *graph);`**
  Frees the memory allocated for the graph.

---

### **Graph Traversal**
- **`void dfs_print(const struct Graph *graph);`**
  Performs a depth-first search (DFS) traversal of the graph and prints the visited vertices.

- **`void bfs_print(const struct Graph *graph);`**
  Performs a breadth-first search (BFS) traversal of the graph and prints the visited vertices.

---

### **Graph Utilities**
- **`void print_graph(const struct Graph *graph);`**
  Prints the graph's adjacency list.

- **`bool is_neighbor(const struct Graph *graph, int src, int find);`**
  Checks if `find` is a direct neighbor of `src`.

- **`bool same_component(const struct Graph *graph, int src, int dest);`**
  Checks if `src` and `dest` are in the same connected component.

- **`bool is_connected(const struct Graph *graph);`**
  Checks if the entire graph is connected.

- **`size_t in_degree(const struct Graph *graph, int vertex);`**
  Computes the in-degree of a vertex.

- **`size_t out_degree(const struct Graph *graph, int vertex);`**
  Computes the out-degree of a vertex.

- **`int *smallest_path(const struct Graph *graph, int start, int stop);`**
  Finds the shortest path between `start` and `stop` vertices. Returns a dynamically allocated array terminated by `-3`.

- **`int *topological_sort(const struct Graph *graph);`**
  Performs a topological sort of the graph and returns the sorted order as a dynamically allocated array.

---

## Compiling the Library with CMake

### Step 1: Create a Build Directory
Although the build files will be generated in a separate directory, the final library will be placed in the project root.

```bash
mkdir build
```

### Step 2: Configure the Project
Run the following command from the project root:

```bash
cmake -S . -B build
```

### Step 3: Build the Project
Execute the build command:

```bash
cmake --build build
```

### Step 4: Cleaning Up
After the build completes, you will find the static library `libgraph.a` in the project root directory.

To clean up the build files, simply remove the `build` directory:

```bash
rm -rf build
```

---

## **Using `libgraph.a` in Your Program**

### **Step 1: Include Headers**
Include the necessary headers in your program:

```c
#include "graph.h"
#include "utils.h"
```

### **Step 2: Link the Library**
Compile your program with `libgraph.a` using the following command:

```bash
gcc -std=c99 -Wall -Wextra -Werror -Iinclude -o my_program your_program.c -L. -lgraph
```

- **`-L.`** : Specifies the directory where `libgraph.a` is located.
- **`-lgraph`** : Links against `libgraph.a`.

### **Step 3: Execute Your Program**
Run the compiled program:

```bash
./my_program
```

---

## **Example Program**

Here is a simple example demonstrating how to use `libgraph`:

```c
#include <stdio.h>
#include "graph.h"
#include "utils.h"

int main(void) {
    struct Graph *graph = graph_init(5, true);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 3);
    add_edge(graph, 1, 2);
    add_edge(graph, 4, 0);
    add_edge(graph, 4, 3);

    printf("Graph Representation:\n");
    print_graph(graph);

    printf("\nIs 0 \u2192 1 a neighbor? %s\n", is_neighbor(graph, 0, 1) ? "Yes" : "No");
    printf("In-degree of vertex 3: %zu\n", in_degree(graph, 3));
    printf("Out-degree of vertex 0: %zu\n", out_degree(graph, 0));

    int *path = smallest_path(graph, 0, 3);
    if (path) {
        printf("\nShortest path from 0 to 3: ");
        for (int i = 0; path[i] != -3; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        free(path);
    } else {
        printf("No path found from 0 to 3.\n");
    }

    int *sorted = topological_sort(graph);
    if (sorted) {
        printf("\nTopological Order: ");
        for (int i = 0; i < graph->order; i++) {
            printf("%d ", sorted[i]);
        }
        printf("\n");
        free(sorted);
    } else {
        printf("Topological sort failed.\n");
    }

    free_graph(graph);
    return 0;
}
```

