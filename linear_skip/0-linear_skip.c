#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @head: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *jump;

	if (!head)
		return (NULL);

	jump = head->express;
	while (jump && jump->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", jump->index, jump->n);
		head = jump;
		jump = jump->express;
	}

	if (!jump)
	{
		jump = head;
		while (jump->next)
			jump = jump->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       head->index, jump->index);

	while (head && head->index <= jump->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", head->index, head->n);
		if (head->n == value)
			return (head);
		head = head->next;
	}

	return (NULL);
}

