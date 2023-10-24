#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers within an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmps;

	tmps = *a;
	*a = *b;
	*b = tmps;
}

/**
 * hoare_partition - Rearrange a subset the Hoare partition scheme.
 * @array: The integer array to be partitioned.
 * @size: The size of the array.
 * @left: The starting index of the subset to be ordered.
 * @right: The ending index of the subset to be ordered.
 *
 * Return: The final partition index.
 *
 * Description: Utilizes the Hoare and the last element as the pivot.
 * It prints the array after each swap operation.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivots, above, below;

	pivots = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivots);
		do {
			below--;
		} while (array[below] > pivots);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm and Hoare partition scheme.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the array partition to be ordered.
 * @right: The ending index of the array partition to be ordered.
 *
 * Description: Sorts the array through recursive calls, employing  scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int parts;

	if (right - left > 0)
	{
		parts = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, parts - 1);
		hoare_sort(array, size, parts, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Ascending order using the quicksort algorithm with scheme.
 * It also prints the array after each swap operation.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

