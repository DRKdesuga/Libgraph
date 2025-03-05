#include "fifo.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *fifi = malloc(sizeof(struct fifo));
    if (!fifi)
    {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    fifi->head = NULL;
    fifi->tail = NULL;
    fifi->size = 0;
    return fifi;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo ? fifo->size : 0;
}

bool fifo_is_empty(const struct fifo *fifo)
{
    return !fifo || fifo->size == 0;
}

void fifo_push(struct fifo *fifo, int elt)
{
    if (!fifo)
    {
        return;
    }

    struct list *new_node = malloc(sizeof(struct list));
    if (!new_node)
    {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    new_node->data = elt;
    new_node->next = NULL;

    if (fifo->tail)
    {
        fifo->tail->next = new_node;
    }
    else
    {
        fifo->head = new_node;
    }

    fifo->tail = new_node;
    fifo->size += 1;
}

int fifo_head(struct fifo *fifo)
{
    if (fifo_is_empty(fifo))
    {
        fprintf(stderr, "Erreur : tentative de lecture d'une file vide\n");
        exit(EXIT_FAILURE);
    }

    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo_is_empty(fifo))
    {
        return;
    }

    struct list *old_head = fifo->head;
    fifo->head = fifo->head->next;

    if (!fifo->head)
    {
        fifo->tail = NULL;
    }

    free(old_head);
    fifo->size -= 1;
}

void fifo_clear(struct fifo *fifo)
{
    if (!fifo)
    {
        return;
    }

    while (!fifo_is_empty(fifo))
    {
        fifo_pop(fifo);
    }
}

void fifo_destroy(struct fifo *fifo)
{
    if (!fifo)
    {
        return;
    }

    fifo_clear(fifo);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    if (!fifo)
    {
        return;
    }

    struct list *current = fifo->head;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
