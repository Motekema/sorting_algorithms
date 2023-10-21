#include "sort.h"
#include <stdio.h>

/**
 * print_list - It prints list of integers
 *
 * @list: List - be printed
 */
void print_list(const listint_t *list)
{
	int x;

	x = 0;
	while (list)
	{
		if (x > 0)
			printf(", ");
		printf("%d", list->n);
		++x;
		list = list->next;
	}
	printf("\n");
}
