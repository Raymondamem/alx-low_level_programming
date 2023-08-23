#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning
 * of the dlistint_t list
 *
 * @head: head of the list
 * @n: value of the lists element
 * Return: the address of the new lists element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_;
	dlistint_t *h_;

	new_ = malloc(sizeof(dlistint_t));
	if (new_ == NULL)
		return (NULL);

	new_->n = n;
	new_->prev = NULL;
	h_ = *head;

	if (h_ != NULL)
	{
		while (h_->prev != NULL)
			h_ = h_->prev;
	}

	new_->next = h_;

	if (h_ != NULL)
		h_->prev = new_;

	*head = new_;

	return (new_);
}
