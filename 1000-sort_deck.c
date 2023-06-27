#include "deck.h"

/**
 * get_value - gets the value of the card in numerical format for comparison
 * @node: the card to get it's value
 *
 * Return: returns the value of the card(an integer value)
 */
int get_value(deck_node_t *node)
{
	int value, i = 0;
	int card_val[13] = {'A', '2', '3', '4', '5', '6', '7',
			    '8', '9', '1', 'J', 'Q', 'K'};
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

	while (i < 13)
	{
		if (node->card->value[0] == card_val[i])
			value = num[i];
		i++;
	}

	return (value);
}

/**
 * kind_sort - sorts the deck of cards based on the kind of card
 * @deck: the deck of cards to be sorted
 * Description: Implemented using the insertion sort algorithm
 */
void kind_sort(deck_node_t **deck)
{
	deck_node_t *current, *next, *temp;

	for (next = (*deck)->next; next != NULL; next = temp)
	{
		temp = next->next;
		current = next->prev;

		while (current != NULL &&
		       current->card->kind > next->card->kind)
		{
			current->next = next->next;
			if (next->next)
				next->next->prev = current;
			next->prev = current->prev;
			next->next = current;
			if (current->prev)
				current->prev->next = next;
			else
				*deck = next;
			current->prev = next;
			current = next->prev;
		}
	}
}

/**
 * value_sort - sorts the deck of cards based on the value of the card
 * @deck: the deck of cards to be sorted
 * Description: implemented using the insertion sort algorithm
 */
void value_sort(deck_node_t **deck)
{
	deck_node_t *current, *next, *temp;

	for (next = (*deck)->next; next != NULL; next = temp)
	{
		temp = next->next;
		current = next->prev;

		while (current != NULL &&
		       current->card->kind == next->card->kind &&
		       get_value(current) > get_value(next))
		{
			current->next = next->next;
			if (next->next)
				next->next->prev = current;
			next->prev = current->prev;
			next->next = current;
			if (current->prev)
				current->prev->next = next;
			else
				*deck = next;
			current->prev = next;
			current = next->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck of card based on kind and value of card
 * Description: Uses the insertion sort method to sort the deck of cards
 * @deck: the deck of cards to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || !((*deck)->next))
		return;

	kind_sort(deck);
	value_sort(deck);
}
