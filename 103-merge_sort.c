#include "sort.h"

/**
 * merge_array - compares and merges the array into a sorted array
 * @copy: buffer to store a copy of the array
 * @array: the array to sort
 * @left: the left most index
 * @right: the right most index
 * @mid: the mid item(index)
 */
void merge_array(int *copy, int *array, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(copy + left, mid - left);
	printf("[right]: ");
	print_array(copy + mid, right - mid);

	while (k < right)
	{
		if (i < mid && (j >= right || copy[i] <= copy[j]))
		{
			array[k] = copy[i];
			i++;
		}
		else
		{
			array[k] = copy[j];
			j++;
		}
		k++;
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * split - splits the array into halves which would be merged to sort the array
 * @copy: a buffer to store a copy of the array
 * @array: the array to split and sort
 * @left: index of the left most item
 * @right: the index of the right most item
 */
void split(int *copy, int *array, size_t left, size_t right)
{
	size_t mid = 0;

	if (right - left < 2)
		return;

	mid = (left + right) / 2;
	split(copy, array, left, mid);
	split(copy, array, mid, right);
	merge_array(copy, array, left, mid, right);

	for (mid = left; mid < right; mid++)
		copy[mid] = array[mid];
}

/**
 * merge_sort - sorts the given array using the merge sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *array_copy;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;

	array_copy = malloc(sizeof(int) * size);
	if (array_copy == NULL)
		return;

	/* copy the array to the buffer */
	while (i < size)
	{
		array_copy[i] = array[i];
		i++;
	}

	split(array_copy, array, 0, size);

	free(array_copy);
}
