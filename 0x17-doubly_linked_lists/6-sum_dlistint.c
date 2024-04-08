#include "lists.h"

/**
 * sum_dlistint - returnssum
 * @head: pointer to head of list
 * Return: sum of all data, or 0 if list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum = 0;

	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
