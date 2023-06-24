#include "sort.h"

/**
 * counting_sort - sorts an array using the counting sort algorithm
 * @array: the array to sort
 * @size: size of the array to sort
 */
void counting_sort(int *array, size_t size)
{
	size_t i = 1;
	int *count, k = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	/* find largest item in the array (k) */
	k = array[0];
	for (; i < size; i++)
		if (array[i] > k)
			k = array[i];
	/* allocate memory of size k + 1 for the new array */
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (j = 0; j <= k; j++) /* initialize memory with 0s */
		count[j] = 0;
	for (i = 0; i < size; i++) /* increment index if element present */
		count[array[i]] += 1;
	/* find cummulative frequency of the new array */
	for (j = 0; j <= k; j++)
		count[j + 1] += count[j];
	print_array(count, k + 1);
	/* replace items in a sorted manner in old list */
	for (i = 0; i < size; i++)
	{
		j = count[array[i]] - 1;
		if (array[i] != array[j])
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}
	free(count); /* free allocated memory block */
}
