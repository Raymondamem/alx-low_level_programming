#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * find_listint_loop - prototype
 * @head: pointer to list
 * Returns: The address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		return (slow);
		}
	}
	return (NULL);
}
