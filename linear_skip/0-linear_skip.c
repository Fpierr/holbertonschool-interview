#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express;

    if (!list)
        return (NULL);

    express = list->express;

    while (express && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);
        list = express;
        express = express->express;
    }

    if (express)
        printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);
    else
    {
        express = list;
        while (express->next)
            express = express->next;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", list->index,
		    express->index);

    while (list && list->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        if (list->n == value)
            return (list);
        list = list->next;
    }

    return (NULL);
}
