#ifndef FIFO_H
#define FIFO_H

#include <stdbool.h>
#include <stddef.h>

// Structure of a node in the linked list
struct list
{
    int data;
    struct list *next;
};

// Structure of the queue (FIFO)
struct fifo
{
    struct list *head; // Pointer to the first element
    struct list *tail; // Pointer to the last element
    size_t size; // Number of elements in the queue
};

// Initializes the queue
struct fifo *fifo_init(void);

// Returns the size of the queue
size_t fifo_size(struct fifo *fifo);

// Checks if the queue is empty
bool fifo_is_empty(const struct fifo *fifo);

// Adds an element to the end of the queue
void fifo_push(struct fifo *fifo, int elt);

// Returns the element at the front of the queue
int fifo_head(struct fifo *fifo);

// Removes the element at the front of the queue
void fifo_pop(struct fifo *fifo);

// Clears all elements in the queue
void fifo_clear(struct fifo *fifo);

// Destroys the queue and frees memory
void fifo_destroy(struct fifo *fifo);

// Prints the elements in the queue
void fifo_print(const struct fifo *fifo);

#endif /* FIFO_H */
