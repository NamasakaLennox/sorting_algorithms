#include "sort.h"

/**
 * split - partitions the array using the last element
 * @array: the array to split
 * @low: the index of the far left item of partition
 * @high: index of the far most right item
 * @size: size of the array
 *
 * Return: returns the index of the new pivot element
 */
int split(int *array, int low, int high, size_t size)
{
	int i = low - 1, temp, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i < j) /* swap */
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high]) /* move furthest right */
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * recursive_sort - sort the array recursively using quick sort algorithm
 * @array: the array to sort
 * @low: the index of the far left item of partition
 * @high: index of the far most right item
 * @size: size of the array
 */
void recursive_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = split(array, low, high, size);
		recursive_sort(array, low, pivot - 1, size);
		recursive_sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array that is being sorted
 * Description: the quick sort algorithm is implemented using recursion
 */
void quick_sort(int *array, size_t size)
{
	recursive_sort(array, 0, size - 1, size);
}
