#include "sort.h"

/**
 * merge_array - compares and merges the array into a sorted array
 * @copy: buffer to store a copy of the array
 * @array: the array to sort
 * @left: the left most index
 * @right: the right most index
 * @mid: the mid item(index)
 */
void merge_array(int *copy, int *array, int left, int mid, int right)
{
	int i, j, k;

	printf("Merging...\n");
	printf("left: ");
	print_array(copy + left, mid - left);
	printf("right: ");
	print_array(copy + mid, right - mid + 1);

	i = left;
	j = mid;
	k = left;

	/* merge and sort */
	while (k <= right)
	{
		if (i < mid && j <= right)
		{
			/* swap */
			if (copy[i] > copy[j])
				array[k++] = copy[j++];
			else /* maintain their index */
				array[k++] = copy[i++];
		}
		else if (i < mid)
			array[k++] = copy[i++];
		else
			array[k++] = copy[j++];
	}

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * split - splits the array into halves which would be merged to sort the array
 * @copy: a buffer to store a copy of the array
 * @array: the array to split and sort
 * @left: index of the left most item
 * @right: the index of the right most item
 */
void split(int *copy, int *array, int left, int right)
{
	int mid, diff;

	if (left < right)
	{
		diff = right - left;
		diff += diff % 2;
		mid = left + (diff / 2);

		split(copy, array, left, mid - 1);
		split(copy, array, mid, right);

		merge_array(copy, array, left, mid, right);
	}
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
		exit(EXIT_FAILURE);

	/* copy the array to the buffer */
	while (i < size)
	{
		array_copy[i] = array[i];
		i++;
	}

	split(array_copy, array, 0, size - 1);
	free(array_copy);
}
