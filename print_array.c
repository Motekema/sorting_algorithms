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
	size_t x;

	x = 0;
	while (array && x < size)
	{
		if (x > 0)
			printf(", ");
		printf("%d", array[x]);
		++x;
	}
	printf("\n");
}
