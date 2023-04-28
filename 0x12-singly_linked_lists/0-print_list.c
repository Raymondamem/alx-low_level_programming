#include "lists.h"
#include "main.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;
	const list_t *temp_node = h;

	while (temp_node != NULL)
	{
		if (temp_node->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", temp_node->len, temp_node->str);
		temp_node = temp_node->next;
		count++;
	}
	return (count);
}
