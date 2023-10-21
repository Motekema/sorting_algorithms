#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - It prints array of integers
 *
 * @array: Array - be printed
 * @size: Numb of elements in an @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
