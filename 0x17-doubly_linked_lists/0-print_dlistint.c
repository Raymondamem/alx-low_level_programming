#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current_d;
	size_t size = 0;

	current_d = h;
	while (current_d != NULL)
	{
		printf("%d\n", current_d->n);
		current_d = current_d->next;
		size++;
	}
	return (size);
}
