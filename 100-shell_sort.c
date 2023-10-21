#include "sort.h"

/**
 * swap_ints - It swaps two integers in array.
 * @a: First integer - swap.
 * @b: Second integer - swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - It sorts array of integers in ascending
 *              order using shell sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Desc: It ses Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, x, l;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (x = gap; x < size; x++)
		{
			l = x;
			while (l >= gap && array[l - gap] > array[l])
			{
				swap_ints(array + l, array + (l - gap));
				l -= gap;
			}
		}
		print_array(array, size);
	}
}
