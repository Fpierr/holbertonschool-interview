#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Creates a new node with a copy of the given string
 * @str: String to copy
 * Return: Pointer to the new node or NULL on failure
 */
static List *create_node(char *str)
{
	List *node;
	char *dup;

	node = malloc(sizeof(List));
	if (!node)
		return (NULL);

	dup = strdup(str);
	if (!dup)
	{
		free(node);
		return (NULL);
	}
	node->str = dup;
	node->prev = node->next = NULL;

	return (node);
}

/**
 * add_node_end - Adds a new node at the end of a circular doubly linked list
 * @list: Pointer to the head pointer of the list
 * @str: String to copy into the new node
 * Return: Address of the new node or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node, *tail;

	if (!list)
		return (NULL);

	node = create_node(str);

	if (!node)
		return (NULL);

	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
	}
	else
	{
		tail = (*list)->prev;
		tail->next = node;
		node->prev = tail;
		node->next = *list;
		(*list)->prev = node;
	}
	return (node);
}

/**
 * add_node_begin - Adds a new node at the beginning
 * @list: Pointer to the head pointer of the list
 * @str: String to copy into the new node
 * Return: Address of the new node or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node;

	node = add_node_end(list, str);

	if (!node)
		return (NULL);

	*list = node;

	return (node);
}
