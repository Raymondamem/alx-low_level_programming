#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint_safe - function to free lists
 * @h: the pointer to the stucts
 * Return: count of structs
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *slow, *fast, *tmp;

	if (h == NULL || *h == NULL)
		return (0);
	slow = *h;
	fast = *h;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		tmp = slow;
		slow = slow->next;
		fast = fast->next->next;
		free(tmp);
		count++;

		if (slow == fast)
		{
			tmp = slow;
			slow = slow->next;
			free(tmp);
			count++;
			break;
		}
	}

	while (slow != NULL)
	{
		tmp = slow;
		slow = slow->next;
		free(tmp);
		count++;
	}

	*h = NULL;

	return (count);
}
