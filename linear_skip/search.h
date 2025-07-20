#ifndef SEARCH_H
#define SEARCH_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct skiplist_s - Node in a singly linked list with express lane
 * @n: Value stored in node
 * @index: Position in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next express node
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* Core search algorithm */
skiplist_t *skip_search(skiplist_t *head, int target);

/* Utility functions (optional for testing) */
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

#endif /* SEARCH_H */

