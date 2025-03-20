#ifndef FIFO_H
#define FIFO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief STruct that represent a Node in the linked list
 *
 * Contais an int that represent the stored data and
 * a pointer to the next element
 */
struct list
{
    int data;
    struct list *next;
};

/**
 * @brief Main FIFO struct
 *
 * This strcut handle fifo data structure storing
 * a head and a tail pointer and a the actual size of the fifo
 */
struct fifo
{
    struct list *head;
    struct list *tail;
    size_t size;
};

/**
 * @brief Initialisation function
 *
 * Init a new fifo
 *
 * @return A pointer to the new allocated fifo
 */
struct fifo *fifo_init(void);

/**
 * @brief Getter for the fifo size
 *
 * get the actual size of the fifo
 *
 * @param pointer to the FIFO structure.
 * @return the size of the fifo
 */
size_t fifo_size(struct fifo *fifo);

/**
 * @brief Checks if the fifo is empty or not.
 *
 * Determines whether the given fifo structure contains any elements.
 *
 * @param pointer to the fifo structure.
 * @return true if the fifo is empty, false otherwise.
 */
bool fifo_is_empty(const struct fifo *fifo);

/**
 * @brief Adds an element to the fifo.
 *
 * Adds the given int element to the fifo structure.
 *
 * @param fifo pointer to the fifo structure.
 * @param elt the element to add.
 */
void fifo_push(struct fifo *fifo, int elt);

/**
 * @brief Returns the first element of the fifo.
 *
 * Show the element at the head of the fifo structure without removing it.
 *
 * @param pointer to the fifo structure.
 * @return The first element of the fifo.
 */
int fifo_head(struct fifo *fifo);

/**
 * @brief Removes the first element from the fifo.
 *
 * Removes the element at the head of the fifo structure.
 *
 * @param fifo pointer to the fifo structure.
 */
void fifo_pop(struct fifo *fifo);

/**
 * @brief Clears the fifo.
 *
 * cClear all elements from the fifo structure.
 *
 * @param fifo pointer to the fifo structure.
 */
void fifo_clear(struct fifo *fifo);

/**
 * @brief Destroys the fifo.
 *
 * Frees all resources allocated for the fifo structure and destroys it.
 *
 * @param fifo pointer to the fifo structure.
 */
void fifo_destroy(struct fifo *fifo);

/**
 * @brief Prints the fifo.
 *
 * PRints the content of the fifo structure to the standard output.
 *
 * @param fifo pointer to the fifo structure.
 */
void fifo_print(const struct fifo *fifo);

#endif /* FIFO_H */
