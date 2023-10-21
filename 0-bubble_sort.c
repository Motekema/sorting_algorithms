#include "sort.h"

/**
 * swap_ints - It swap two integers in array
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
 * bubble_sort - It sort array of integers in ascending order.
 * @array: Array integers to sort.
 * @size: Size of array.
 *
 * Description: It prints array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (x = 0; x < len - x; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_ints(array + x, array + x + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
