#include "search.h"

/**
 * skip_search - Searches for a number in a sorted skip list.
 * @head: Start of the list.
 * @target: Value to find.
 * Return: Pointer to node or NULL.
 */
skiplist_t *skip_search(skiplist_t *head, int target)
{
	skiplist_t *jump = NULL;

	if (!head)
		return (NULL);

	for (jump = head->express; jump && jump->n < target;
			head = jump, jump = jump->express)
		printf("Checked index [%lu] = [%d]\n", jump->index, jump->n);

	if (!jump)
		for (jump = head; jump->next; jump = jump->next)
			;

	printf("Searching in range [%lu] to [%lu]\n", head->index, jump->index);

	while (head && head->index <= jump->index)
	{
		printf("Checked index [%lu] = [%d]\n", head->index, head->n);
		if (head->n == target)
			return (head);
		head = head->next;
	}
	return (NULL);
}

