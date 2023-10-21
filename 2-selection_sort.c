#include "sort.h"

/**
 * swap_ints - It wap two integers in array
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - It sort array of integers in ascending order
 *                  using selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Des: Prints array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t x, l;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = array + x;
		for (l = x + 1; l < size; l++)
			min = (array[l] < *min) ? (array + l) : min;

		if ((array + x) != min)
		{
			swap_ints(array + x, min);
			print_array(array, size);
		}
	}
}
