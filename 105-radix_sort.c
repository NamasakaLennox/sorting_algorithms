#include "sort.h"

/**
 * get_max - gets the maximum value in the array
 * @array: the array to get the max value
 * @size: the size of the array
 *
 * Return: returns the maximum value in the array of numbers
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}


/**
 * count_sort - sorts each place value using the count sort method
 * @array: the array to sort
 * @size: size of the array
 * @exp: the exponential value
 * @out: a temporary array to store copy of the values
 */
void count_sort(int *array, size_t size, int exp, int *out)
{
	int i, count[10] = {0};

	/* storeth count of occurrences */
	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	/* change so the count[i] now contains the position of digit in out */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* build output array */
	for (i = size - 1; i >= 0; i--)
	{
		out[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* copy the sorted output array to the initial array */
	for (i = 0; i < (int)size; i++)
		array[i] = out[i];
}

/**
 * radix_sort - sorts an array using the radix sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array to sort
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, exp, *out = NULL;

	if (array == NULL || size < 2)
		return;

	/* get the maximum number in the array */
	max = get_max(array, size);

	out = malloc(size * sizeof(int));
	if (out == NULL)
		return;

	/* do a counting sort for every digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp, out);
		print_array(array, size);
	}
	free(out);
}
