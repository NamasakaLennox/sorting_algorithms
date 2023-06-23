#include "sort.h"

/**
 * insertion_sort_list - sorts a list by insertion sort method
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *previous, *current;

	if (list == NULL)
		return;
	head = *list;

	while (head)
	{
		current = head;
		previous = head->prev;
		while (previous && current)
		{
			/* swap if previous is larger */
			if (previous->n > current->n)
			{
				previous->next = current->next;
				if (current->next)
					current->next->prev = previous;
				current->next = previous;
				current->prev = previous->prev;
				if (previous->prev)
					previous->prev->next = current;
				previous->prev = current;
				if (current == head)
					head = previous;
				previous = current->prev;
			}
			else
				break;

			if (previous == NULL)
				*list = current;
			print_list(*list);
		}
		head = head->next;
	}
}
