#include "sort.h"

/**
 * get_max - Get maximum value in an array of integers.
 * @array: An a array of integers.
 * @size: The size of the arrays.
 *
 * Return: The maximum integers in the array.
 */
int get_max(int *array, int size)
{
	int max, z;

	for (max = array[0], z = 1; z < size; z++)
	{
		if (array[z] > max)
			max = array[z];
	}

	return (max);
}

/**
 * counting_sort - Sort a array of integers in ascending order
 *                 using the countings sort algorithm.
 * @array: An array of integer.
 * @size: The size of the arrays.
 *
 * Description: Prints the count array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, z;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (z = 0; z < (max + 1); z++)
		count[z] = 0;
	for (z = 0; z < (int)size; z++)
		count[array[z]] += 1;
	for (z = 0; z < (max + 1); z++)
		count[z] += count[z - 1];
	print_array(count, max + 1);

	for (z = 0; z < (int)size; z++)
	{
		sorted[count[array[z]] - 1] = array[z];
		count[array[z]] -= 1;
	}

	for (z = 0; z < (int)size; z++)
		array[z] = sorted[z];

	free(sorted);
	free(count);
}
