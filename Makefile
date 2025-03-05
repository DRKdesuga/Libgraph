CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -Iinclude

SRC = src/fifo.c src/graph.c src/traversal.c src/utils.c
OBJ = $(SRC:.c=.o)

LIBRARY_NAME = libgraph.a

.PHONY: library clean

# Rule to generate the static library
library: $(OBJ)
	ar csr $(LIBRARY_NAME) $(OBJ)

# Clean up object files and the library
clean:
	rm -f $(OBJ) $(LIBRARY_NAME)
