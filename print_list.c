#include "sort.h"
#include <stdio.h>

/**
 * print_list - It prints list of integers
 *
 * @list: List - be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
