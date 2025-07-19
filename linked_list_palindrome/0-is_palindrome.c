#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to head of list
 * Return: Pointer to new head (reversed list)
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *next = NULL;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

/**
 * compare_lists - Compares two linked lists for equality
 * @h1: First list
 * @h2: Second list
 * Return: 1 if identical, 0 otherwise
 */
int compare_lists(listint_t *h1, listint_t *h2)
{
	while (h1 && h2)
	{
		if (h1->n != h2->n)
			return (0);
		h1 = h1->next;
		h2 = h2->next;
	}
	return (1);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to head of list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *rev, *tmp;

	if (!head || !*head || !(*head)->next)
		return (1);

	slow = *head;
	fast = *head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	rev = reverse_list(slow);
	tmp = rev;

	if (!compare_lists(*head, rev))
	{
		reverse_list(tmp); /* Restore list */
		return (0);
	}

	reverse_list(tmp); /* Restore list */
	return (1);
}

