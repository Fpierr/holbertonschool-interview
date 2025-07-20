#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @head: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express = list;

    if (!list)
        return (NULL);

    while (express->express && express->express->n < value)
    {
        express = express->express;
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
    }

    /* Afficher la dernière vérification express (même si >= value) */
    if (express->express)
    {
        express = express->express;
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", list->index, express->index);

    /* Recherche linéaire classique entre list et express */
    while (list && list->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        if (list->n == value)
            return (list);
        list = list->next;
    }

    return (NULL);
}
