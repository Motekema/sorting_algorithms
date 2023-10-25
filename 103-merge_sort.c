#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort subarray of integers.
 * @subarr: Subarray of an array of integers to sort.
 * @buff: Buffer to store the sorted subarray.
 * @front: The front index of a array.
 * @mid: The middle index of a array.
 * @back: The back index of a array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, z, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, z = mid; i < mid && z < back; k++)
		buff[k] = (subarr[i] < subarr[z]) ? subarr[i++] : subarr[z++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; z < back; z++)
		buff[k++] = subarr[z];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement a merge sort algorithm through recursion.
 * @subarr: A subarray of an array of a integers to sort.
 * @buff: A buffer to store a sorted result.
 * @front: The front index of a subarray.
 * @back: The back index of a subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mids;

	if (back - front > 1)
	{
		mids = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mids);
		merge_sort_recursive(subarr, buff, mids, back);
		merge_subarr(subarr, buff, front, mids, back);
	}
}

/**
 * merge_sort - Sort a array of integers in ascending
 *              order using a merge sort algorithm.
 * @array: Array of integers.
 * @size: The size ofa array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffur;

	if (array == NULL || size < 2)
		return;

	buffur = malloc(sizeof(int) * size);
	if (buffur == NULL)
		return;

	merge_sort_recursive(array, buffur, 0, size);

	free(buffur);
}
