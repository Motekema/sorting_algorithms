#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked node ahead.
 * @list: A pointer to the list's head.
 * @tail: A pointer to the list's tail.
 * @shaker: A pointer to the current node in the cocktail shaker algorithm.
 */


void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swap a node in listint_t doubly-linked list node behind.
 * @list: A pointer to the list's head.
 * @tail: A pointer to the list's tail.
 * @shaker: A pointer to the current node in the cocktail shaker algorithm.
 */


void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmps = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmps;
	else
		*tail = tmps;
	tmps->next = (*shaker)->next;
	(*shaker)->prev = tmps->prev;
	if (tmps->prev != NULL)
		tmps->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmps;
	tmps->prev = *shaker;
	*shaker = tmps;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list in ascending order
 *                     using the cocktail shaker algorithm.
 * @list: A pointer to the list's head.
 *
 * Description: Sorts a list of integers using the cocktail shaker algorithm
 * and prints the list at each swap operation.
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *tails, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tails = *list; tails->next != NULL;)
		tails = tails->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tails; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tails, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tails, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
