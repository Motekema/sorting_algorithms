#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void sort_deck(deck_node_t **deck);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */


int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */


char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
	        return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort deck of cards by kind (from spades to diamonds).
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */


void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iters, *insert, *tmp;

	for (iters = (*deck)->next; iters != NULL; iters = tmp)
	{
		tmp = iters->next;
		insert = iters->prev;
		while (insert != NULL && insert->card->kind > iters->card->kind)
		{
			insert->next = iters->next;
			if (iters->next != NULL)
				iters->next->prev = insert;
			iters->prev = insert->prev;
			iters->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iters;
			else
				*deck = iters;
			insert->prev = iters;
			insert = iters->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck of cards by value (ace to king).
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */


void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iters, *insert, *tmp;

	for (iters = (*deck)->next; iters != NULL; iters = tmp)
	{
		tmp = iters->next;
		insert = iters->prev;
		while (insert != NULL &&
		       insert->card->kind == iters->card->kind &&
		       get_value(insert) > get_value(iters))
		{
			insert->next = iters->next;
			if (iters->next != NULL)
				iters->next->prev = insert;
			iters->prev = insert->prev;
			iters->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iters;
			else
				*deck = iters;
			insert->prev = iters;
			insert = iters->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards by kind (from spades to diamonds)
 *             and then by value (ace to king).
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */


void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
