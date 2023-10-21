#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Its Doubly linked list node
 *
 * @n: Integer stored in node
 * @prev: Pointer - previous element of list
 * @next: Pointer - next element of list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prints helper functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* Sorting algoritms */
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size)
void merge_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);;

#endif /* SORT_H */
