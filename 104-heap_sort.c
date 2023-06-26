#include "sort.h"

/**
 * swap_nodes - swaps the roots of the binary tree
 * @array: the array to be sorted
 * @root: the root of the heap
 * @upper: the higher index
 * @size: the size of the array
 */
void swap_nodes(int *array, size_t root, size_t upper, size_t size)
{
	size_t low = 0, mid = 0, temp = 0;
	int i = 0;

	while ((low = (2 * root + 1)) <= upper)
	{
		temp = root;
		mid = low + 1;
		if (array[temp] < array[low])
			temp = low;
		if (mid <= upper && array[temp] < array[mid])
			temp = mid;
		if (temp == root)
			return;
		i = array[root];
		array[root] = array[temp];
		array[temp] = i;
		print_array(array, size);
		root = temp;
	}
}

/**
 * heap_sort - sorts an array using the heap sort algorithm
 * @array: the array to be sorted
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	size_t upper = 0, gap = 0;
	int temp = 0;

	if (array == NULL || size < 2)
		return;

	for (gap = (size - 2) / 2; 1; gap--)
	{
		swap_nodes(array, gap, size - 1, size);
		if (gap == 0)
			break;
	}

	upper = size - 1;
	while (upper > 0)
	{
		temp = array[upper];
		array[upper] = array[0];
		array[0] = temp;
		print_array(array, size);
		upper--;
		swap_nodes(array, 0, upper, size);
	}
}
