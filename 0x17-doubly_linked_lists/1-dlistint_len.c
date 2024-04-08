#include "lists.h"

/**
 * dlistint_len - returns the number of elements in
 * the double linked list
 *
 * @h: head of the list
 * Return: the number of nodes in it
 */
size_t dlistint_len(const dlistint_t *h)
{
	int count = 0;

	if (h == NULL)
	{
		return (0);
	}
	else
	{
		while (h->prev != NULL)
		{
			h = h->prev;
		}
		while (h != NULL)
		{
			count++;
			h = h->next;
		}
		return (count);
	}
}
