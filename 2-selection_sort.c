#include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm
 * @array: the array to sort
 * @size: size of the array to sort
 */
void selection_sort(int *array, size_t size)
{
	int small_index, temp, flag = 0;
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		small_index = i;
		for (j = i + 1; j < size; j++)
		{
			/* check if there is a smaller element */
			if (array[j] < array[small_index])
			{
				small_index = j;
				flag = 1;
			}
		}
		temp = array[i];
		array[i] = array[small_index];
		array[small_index] = temp;
		if (flag == 1)
			print_array(array, size);
		flag = 0;
	}
}
