#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - It wap two integers in array.
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
 * lomuto_partition - It rder subset of array integers according to
 *                    lomu partition scheme (last element as pivot).
 * @array: Array of integers.
 * @size: Size of array.
 * @left: Starting index of subset to order.
 * @right: Ending index of subset to order.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - It implement quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: The size of array.
 * @left: Starting index of array partition to order.
 * @right: Ending index of array partition to order.
 *
 * Desc: Uses Lomu partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int my_part;

	if (right - left > 0)
	{
		my_part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, my_part - 1);
		lomuto_sort(array, size, my_part + 1, right);
	}
}

/**
 * quick_sort - It Sorts array of integers in ascending
 *              order using quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Des: It uses Lomuto partition schemes and Prints
 *              array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
